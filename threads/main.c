#include <stdio.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <queue>    

/*
std::mutex mute;

void print(int &var) {

    std::lock_guard<std::mutex> guard(mute);

    //mute.lock();
    for (int i = 0; i < 5; ++i) {
        printf ("var %d in %d\n", var, std::this_thread::get_id());
        ++var;
        std::this_thread::sleep_for (std::chrono::milliseconds (500));
    }
    //mute.unlock();
}

int work(int &a, int b) {
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Thread ID in work: " << std::this_thread::get_id() << '\n';       // Get ID of the current thread     
        std::this_thread::sleep_for(std::chrono::milliseconds (500));
    }
    return a + b;
}

int main() {

    int var = 1;
    int result = 0;
    //std::thread new_thread (work, std::ref (var), 2);                                                     // Make a new thread, pass a pointer to a function                                    

    std::thread new_thread ([&result, &var]() {
        result = work (var, 2);
    });
    //new_thread.ditach();                                                               // Kill the thread when the main thread dies

    for (int i = 0; i < 3; ++i) {
        std::cout << "Thread ID in main: " << std::this_thread::get_id() << '\n';       // Get ID of the current thread     
        std::this_thread::sleep_for(std::chrono::milliseconds (700));                   // Make the current thread sleep
    }

    new_thread.join();   
    
    int value = 0;

    std::thread my_thread1(print, std::ref(value));
    std::thread my_thread2(print, std::ref(value));

    my_thread1.join();
    my_thread2.join();
                                                               // Wait for this thread to die

}
*/

std::mutex the_mutex;

void producer(std::queue<int>& queue) {
    while (true){
        the_mutex.lock();

        int new_value = rand() % 100;
        queue.push(new_value);
        printf ("Thread-producer \"%d\" pushed %d into the queue\n", std::this_thread::get_id(), new_value);

        the_mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds ((rand() % 10) * 100)); 
    }
}

void consumer(std::queue<int>& queue) {
    while (true) {
        the_mutex.lock();

        int new_value = 0;
        if (queue.size() > 0) {
            new_value = queue.front();
            queue.pop();
            printf ("Thread-consumer \"%d\" popped %d\n", std::this_thread::get_id(), new_value);
            std::this_thread::sleep_for(std::chrono::milliseconds ((rand() % 10) * 100)); 
        }

        the_mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds ((rand() % 10) * 100)); 
    }
}

int main(int argc, char *argv[]) {

    std::queue<int> main_queue;

    int producer_num = atoi(argv[1]);
    int consumer_num = atoi(argv[2]);

    std::thread thread_array[producer_num + consumer_num];

    for (int i = 0; i < producer_num; ++i) {
        thread_array[i] = std::thread (producer, std::ref(main_queue));
    }

    for (int i = producer_num; i < producer_num + consumer_num; ++i) {
        thread_array[i] = std::thread (consumer, std::ref(main_queue));     
    }

    for (int i = 0; i < consumer_num + producer_num; ++i) {
        thread_array[i].detach();
    }

    std::this_thread::sleep_for(std::chrono::milliseconds (20000)); 

}