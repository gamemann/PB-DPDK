#pragma once

#include  <linux/types.h>

#include <cmd_line.h>
#include <config.h>

#include "cmd_line.h"
#include "main.h"

#define MAX_PCKT_LEN 0xFFFF
#define MAX_THREADS 4096
#define MAX_PCKT_BURST 32

struct thread_info
{
    const char device[MAX_NAME_LEN];
    struct sequence seq;
    __u16 seq_cnt;
    struct cmd_line cmd;
    struct cmd_line_dpdk cmd_dpdk;
    int id;
    struct xsk_socket_info *xsk_info;
};

void seq_send(const char *interface, struct sequence seq, __u16 seqc, struct cmd_line cmd, struct cmd_line_dpdk cmd_dpdk);