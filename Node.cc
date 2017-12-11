/*
 * Node.cc
 *
 *  Created on:  2017
 *      Author: M
 */

#include <omnetpp.h>
#include <string.h>
#include <Frame_m.h>

class Node: public cSimpleModule
{
private:
    int no_sent;
    int no_rcvd;
    double time_interval;
    int source;
    int destination;

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();

};

Define_Module(Node);
void Node::initialize()
{
    no_sent = 0;
    no_rcvd = 0;
    time_interval = par("time_interval");
    source = getIndex();
    destination = par("destination_address");

    cMessage *msg= new cMessage();
    scheduleAt(0.01, msg);
}

void Node::handleMessage (cMessage *msg)
{
    if(msg->isSelfMessage())
    {
        Frame *out_msg = new Frame();

        out_msg->setSource(source);
        out_msg->setDestination(destination);
        send(out_msg,"out");
        no_sent++;

        scheduleAt(simTime()+time_interval,msg);
    }
    else
    {
        no_rcvd++;

        delete(msg);
    }
}
void Node::finish()
{
    recordScalar("Number of received message", no_rcvd);
    recordScalar("Number of sent message", no_sent);
}
