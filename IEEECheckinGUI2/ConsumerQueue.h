#pragma once

#include <WinSock2.h>
#include <mysql.h>
#include <queue>
#include <boost\thread.hpp>
#include <boost\bind.hpp>

class ConsumerQueue
{
private:
    std::queue<std::string> the_queue;
    mutable boost::mutex the_mutex;
    boost::condition_variable the_condition_variable;
    MYSQL *connection;

public:
    
    ConsumerQueue(MYSQL *Connection)
    {
        connection = Connection;
    }

    void push(std::string const& data)
    {
        boost::mutex::scoped_lock lock(the_mutex);
        the_queue.push(data);
        lock.unlock();
        the_condition_variable.notify_one();
    }

    bool empty() const
    {
        boost::mutex::scoped_lock lock(the_mutex);
        return the_queue.empty();
    }

    void wait_and_pop()
    {
        boost::mutex::scoped_lock lock(the_mutex);
        while(the_queue.empty())
        {
            the_condition_variable.wait(lock);
        }
        
        int query_state;
    
        MYSQL_RES *result;
        MYSQL_ROW row;

        query_state = mysql_query(connection, the_queue.front().c_str());

        the_queue.pop();
    }

    void Consume()
    {
        while(true)
        {
            wait_and_pop();
        }
    }
};