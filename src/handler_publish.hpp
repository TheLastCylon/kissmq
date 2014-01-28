#ifndef _HANDLER_PUBLISH_HPP_
#define _HANDLER_PUBLISH_HPP_

#include <iostream>
#include <string>
#include <unistd.h>

#include <kisscpp/logstream.hpp>
#include <kisscpp/request_handler.hpp>
#include <kisscpp/boost_ptree.hpp>
#include <kisscpp/request_status.hpp>

class PublishHandler : public kisscpp::RequestHandler
{
  public:
    PublishHandler() :
      kisscpp::RequestHandler("publish", "Puts messagse on a queue.")
    {
      kisscpp::LogStream log(-1, __PRETTY_FUNCTION__);
    }

    ~PublishHandler() {};

    void run(const BoostPtree &request, BoostPtree &response);
  protected:
  private:
};

#endif

