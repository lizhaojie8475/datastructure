#ifndef __RECEIVER_HPP__
#define __RECEIVER_HPP__

#include "message_queue.hpp"
#include "dispatcher.hpp"
#include "sender.hpp"

namespace messaging
{
    class receiver
    {
        queue q;
    public:
        operator sender()
        {
            return sender(&q);
        }
        dispatcher wait()
        {
            return dispatcher(&q);
        }
    };
}

#endif