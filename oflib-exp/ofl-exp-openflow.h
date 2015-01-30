/* Copyright (c) 2011, TrafficLab, Ericsson Research, Hungary
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the Ericsson Research nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * Author: Zoltán Lajos Kis <zoltan.lajos.kis@ericsson.com>
 */

#ifndef OFL_EXP_OPENFLOW_H
#define OFL_EXP_OPENFLOW_H 1


#include "../oflib/ofl-structs.h"
#include "../oflib/ofl-messages.h"

/*experimenter messages ofl_exp*/
struct ofl_exp_openflow_msg_header {
    struct ofl_msg_experimenter   header; /* OPENFLOW_VENDOR_ID */

    uint32_t   type;
};

struct ofl_exp_openflow_msg_queue {
    struct ofl_exp_openflow_msg_header   header; /* OFP_EXT_QUEUE_MODIFY|DELETE */

    uint32_t                  port_id;
    struct ofl_packet_queue  *queue;
};


struct ofl_exp_openflow_msg_set_dp_desc {
    struct ofl_exp_openflow_msg_header   header; /* OFP_EXT_SET_DESC */

    char  *dp_desc;
};

/*************************************************************************/
/*experimenter actions ofl_exp*/
struct ofl_exp_openflow_act_header {
    struct ofl_action_experimenter   header; /* OPENFLOW_VENDOR_ID */

    uint32_t   act_type;
};


struct ofl_exp_set_state_action {
    struct ofl_exp_openflow_act_header  header; /* OFPAT_EXP_SET_STATE */

    uint32_t state;
    uint8_t stage_id; /*we have 64 flow table in the pipeline*/
};


int
ofl_exp_openflow_msg_pack(struct ofl_msg_experimenter *msg, uint8_t **buf, size_t *buf_len);

ofl_err
ofl_exp_openflow_msg_unpack(struct ofp_header *oh, size_t *len, struct ofl_msg_experimenter **msg);

int
ofl_exp_openflow_msg_free(struct ofl_msg_experimenter *msg);

char *
ofl_exp_openflow_msg_to_string(struct ofl_msg_experimenter *msg);

/*experimenter action functions*/

int 
ofl_exp_openflow_act_pack(struct ofl_action_header *src, struct ofp_action_header *dst);

ofl_err
ofl_exp_openflow_act_unpack(struct ofp_action_header *src, size_t *len, struct ofl_action_header **dst);

size_t
ofl_exp_openflow_act_ofp_len(struct ofl_action_header *act);

int     
ofl_exp_openflow_act_free(struct ofl_action_header *act);

char *
ofl_exp_openflow_act_to_string(struct ofl_action_header *act);

#endif /* OFL_EXP_OPENFLOW_H */
