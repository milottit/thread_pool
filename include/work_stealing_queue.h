#ifndef WORK_STEALING_QUEUE_H
#define WORK_STEALING_QUEUE_H
#include "function_wrapper.h"
#include <deque>
#include <mutex>

class work_stealing_queue
{
private:
    typedef function_wrapper data_type;
    std::deque<data_type> the_queue;
    mutable std::mutex the_mutex;
public:
    work_stealing_queue() = default;
    work_stealing_queue(const work_stealing_queue& other)=delete;
    work_stealing_queue& operator=(
        const work_stealing_queue& other)=delete;

    void push(data_type data);
    bool empty() const;
    bool try_pop(data_type& res);
    bool try_steal(data_type& res);
};

#endif // WORK_STEALING_QUEUE_H
