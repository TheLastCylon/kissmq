#include "handler_publish.hpp"

void PublishHandler::run(const BoostPtree &request, BoostPtree &response)
{
  kisscpp::LogStream log(-1, __PRETTY_FUNCTION__);

  /// TODO: Q. What if you end up attempting to create a queue that already existed
  ///       A. Doesn't matter! Response should indicate if queue exists and how many messages are still in it.

  try {

    // Put a message on the named queue.
    // If the queue does not exist, create it first.

    /// Parameters
    /// kmq-name : The name of the queue in question
    /// kmq-rqid : The Requestor Application's ID.
    /// kmq-strn : The actual 64bit encoded message

    /// Response
    /// kmq-name : The name of the queue in question
    /// kmq-newq : Boolean indicator to show wither the queue already existed, or had to be created.
    /// kmq-size : The current size of the queue

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

