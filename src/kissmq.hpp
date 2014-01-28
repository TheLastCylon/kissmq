#ifndef _KISSMQ_HPP_
#define _KISSMQ_HPP_

#include <boost/thread.hpp>
#include <kisscpp/server.hpp>
#include <kisscpp/logstream.hpp>
#include "handler_echo.hpp"

// ----------------------- TODO: -----------------------------
class kissmq : public kisscpp::Server
{
  public:
    kissmq();
    ~kissmq();

  protected:
    void registerHandlers();

  private:
    kisscpp::RequestHandlerPtr publishHandler;
    kisscpp::RequestHandlerPtr subscribeHandler;
};

#endif

