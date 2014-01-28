# The KISSMQ interfaces

Please be sure to read the [Inter Process Communication] documentation, from the KISSCPP library first.
This document refers to information form there.

In addition to the IPC identifiers specified in the KISSCPP documentation above. KISSMQ defines the following:

## Publishing 
The kcm-cmd identifier has to have the value "publish".
### Request IPCOMM(1-3)
| Identifier | Description                               | typical values                                                                             |
|------------|-------------------------------------------|--------------------------------------------------------------------------------------------|
| kmq-name   | The name of the queue to publish too.     | A unique string identifying the queue.                                                     |
| kmq-rqid   | The Requestor Application's ID.           | A unique string identifying the application making the request.                            |
| kmq-strn   | The actual message to place on the queue. | A base64 bit encoded string, containing the message to be sent to subscribed applications. |
### Response IPCOMM(2-6)
| Identifier | Description                                                                       | typical values                                                                             |
|------------|-----------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------|
| kmq-name   | The name of the queue to publish too.                                             | A unique string identifying the queue.                                                     |
| kmq-newq   | Boolean indicator to show wither the queue already existed, or had to be created. | 0 or 1 : 0 indicates the queue already existed.                                            |
| kmq-size   | The current size of the queue.                                                    | An integer value indicating the number of messages in the queue at the time of the request.|


## Subscribing
The kcm-cmd identifier has to have the value "subscribe".

### Request IPCOMM(1-3)
| Identifier | Description                                                     | typical values                                                                             |
|------------|-----------------------------------------------------------------|--------------------------------------------------------------------------------------------|
| kmq-name   | The name of the queue to subscribe too.                         | A unique string identifying the queue.                                                     |
| kmq-rqid   | The Requestor Application's ID.                                 | A unique string identifying the application making the request.                            |
| kmq-host   | The hostname/ip address where notifications are to be sent too. | A hostname or ip address                                                                   |
| kmq-port   | The Port to use for these notifications.                        | A valid port                                                                               |

### Response IPCOMM(2-6)
| Identifier | Description                                                                       | typical values                                                                             |
|------------|-----------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------|
| kmq-name   | The name of the queue to publish too.                                             | A unique string identifying the queue.                                                     |
| kmq-newq   | Boolean indicator to show wither the queue already existed, or had to be created. | 0 or 1 : 0 indicates the queue already existed.                                            |
| kmq-size   | The current size of the queue.                                                    | An integer value indicating the number of messages in the queue at the time of the request.|

