#ifndef __SENDER_HPP__
#define __SENDER_HPP__
#include "message_queue.hpp"

namespace messaging
{
    class sender
    {
        queue *q;
    public:
        sender():
            q(nullptr)
        {}
        explicit sender(queue *q_):
            q(q_)
        {}
        template<typename Message>
        void send(Message const& msg)
        {
            if(q)
            {
                q->push(msg);
            }
        }
    };
}

#endif