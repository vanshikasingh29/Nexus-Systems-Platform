#ifndef NEXUS_NETWORK_H
#define NEXUS_NETWORK_H

typedef struct
{
    int source_port;

    int destination_port;

    int payload_size;

} NetworkPacket;


void create_packet(
    NetworkPacket *packet,
    int source_port,
    int destination_port,
    int payload_size
);


void print_packet(
    const NetworkPacket *packet
);

#endif