typedef struct rec {                /* outgoing UDP data */
  u_short seq;          /* sequence number */
} Rec;

/* the following are a few definitions from Stevens' unp.h */
#define max(a,b) ((a) > (b) ? (a) : (b))

/* the following are prototypes for the Stevens utilities in util.c */
void *Calloc(size_t n, size_t size);
void Sendto(int fd, const void *ptr, size_t nbytes, int flags,
	    const struct sockaddr *sa, socklen_t salen);
void sig_alrm (int signo);
int process_ip (struct ip *ip, int len);
int recv_dgram ();
void sub_tv (Timeval *plus, Timeval *minus, Timeval *res);
double time_to_double (Timeval *time);
void print_report ();
void send_dgram (int ttl);
int send_probes (int ttl);
void loop_ttl ();
