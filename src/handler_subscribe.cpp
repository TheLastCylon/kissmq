#include "handler_subscribe.hpp"

void SubscribeHandler::run(const BoostPtree &request, BoostPtree &response)
{
  kisscpp::LogStream log(-1, __PRETTY_FUNCTION__);

  try {

    /// Add a subscriber to a named queue.
    /// If the queue does not exist, create it.
    /// TODO: Remmber that we'd like to have configuration to allow for apps
    ///       to be registered to certain queues at startup of kissmq

    // kmq-name : Named queue
    // kmq-rqid : Requestor ID. Yes one application can subscribe another application to a queue.
    // kmq-host : The hostname/ip address where notifications are to be sent too.
    // kmq-port : The Port to use for these notifications.

    // This is where you build your response
    response.put("kcm-sts" , kisscpp::RQST_SUCCESS);                // Make sure to set kcm-sts to RQST_SUCCESS in the event of success
    response.put("you-sent", request.get<std::string>("message"));  // populate any aditional response parameters.

  } catch (boost::property_tree::ptree_bad_path &e) {

    log << "Exception: " << e.what() << kisscpp::manip::endl;
    response.put("kcm-sts", kisscpp::RQST_MISSING_PARAMETER); // Make sure to set "kcm-sts" to the appropriate error status.
    response.put("kcm-erm", e.what());

  } catch (std::exception& e) {

    log << "Exception: " << e.what() << kisscpp::manip::endl;
    response.put("kcm-sts", kisscpp::RQST_UNKNOWN);                    
    response.put("kcm-erm", e.what());

  }
}

