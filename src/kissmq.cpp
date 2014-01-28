#include "kissmq.hpp"

//--------------------------------------------------------------------------------
kissmq::kissmq() : Server("localhost", "9100", 1)
{
  kisscpp::LogStream log(-1, __PRETTY_FUNCTION__, "/tmp/kissmq.log", true);
  registerHandlers();
}

//--------------------------------------------------------------------------------
kissmq::~kissmq()
{
  kisscpp::LogStream log(-1, __PRETTY_FUNCTION__);
  stop();
}

//--------------------------------------------------------------------------------
void kissmq::registerHandlers()
{
  kisscpp::LogStream log(-1, __PRETTY_FUNCTION__);

  publishHandler.reset(new PublishHandler());
  register_handler(publishHandler);

  subscribeHandler.reset(new SubscribeHandler());
  register_handler(subscribeHandler);
}

