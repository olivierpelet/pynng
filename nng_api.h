// THIS FILE WAS AUTOMATICALLY GENERATED BY ./generate_api.sh
typedef struct nng_ctx_s {
 uint32_t id;
} nng_ctx;
typedef struct nng_dialer_s {
 uint32_t id;
} nng_dialer;
typedef struct nng_listener_s {
 uint32_t id;
} nng_listener;
typedef struct nng_pipe_s {
 uint32_t id;
} nng_pipe;
typedef struct nng_socket_s {
 uint32_t id;
} nng_socket;
typedef int32_t nng_duration;
typedef struct nng_msg nng_msg;
typedef struct nng_stat nng_stat;
typedef struct nng_aio nng_aio;
struct nng_sockaddr_inproc {
 uint16_t sa_family;
 char sa_name[(128)];
};
struct nng_sockaddr_path {
 uint16_t sa_family;
 char sa_path[(128)];
};
struct nng_sockaddr_in6 {
 uint16_t sa_family;
 uint16_t sa_port;
 uint8_t sa_addr[16];
 uint32_t sa_scope;
};
struct nng_sockaddr_in {
 uint16_t sa_family;
 uint16_t sa_port;
 uint32_t sa_addr;
};
struct nng_sockaddr_zt {
 uint16_t sa_family;
 uint64_t sa_nwid;
 uint64_t sa_nodeid;
 uint32_t sa_port;
};
struct nng_sockaddr_abstract {
 uint16_t sa_family;
 uint16_t sa_len;
 uint8_t sa_name[107];
};
struct nng_sockaddr_storage {
 uint16_t sa_family;
 uint64_t sa_pad[16];
};
typedef struct nng_sockaddr_inproc nng_sockaddr_inproc;
typedef struct nng_sockaddr_path nng_sockaddr_path;
typedef struct nng_sockaddr_path nng_sockaddr_ipc;
typedef struct nng_sockaddr_in nng_sockaddr_in;
typedef struct nng_sockaddr_in6 nng_sockaddr_in6;
typedef struct nng_sockaddr_zt nng_sockaddr_zt;
typedef struct nng_sockaddr_abstract nng_sockaddr_abstract;
typedef struct nng_sockaddr_storage nng_sockaddr_storage;
typedef union nng_sockaddr {
 uint16_t s_family;
 nng_sockaddr_ipc s_ipc;
 nng_sockaddr_inproc s_inproc;
 nng_sockaddr_in6 s_in6;
 nng_sockaddr_in s_in;
 nng_sockaddr_zt s_zt;
 nng_sockaddr_abstract s_abstract;
 nng_sockaddr_storage s_storage;
} nng_sockaddr;
enum nng_sockaddr_family {
 NNG_AF_UNSPEC = 0,
 NNG_AF_INPROC = 1,
 NNG_AF_IPC = 2,
 NNG_AF_INET = 3,
 NNG_AF_INET6 = 4,
 NNG_AF_ZT = 5,
 NNG_AF_ABSTRACT = 6
};
typedef struct nng_iov {
 void * iov_buf;
 size_t iov_len;
} nng_iov;
extern void nng_fini(void);
extern int nng_close(nng_socket);
extern int nng_socket_id(nng_socket);
extern int nng_socket_set(nng_socket, const char *, const void *, size_t);
extern int nng_socket_set_bool(nng_socket, const char *, bool);
extern int nng_socket_set_int(nng_socket, const char *, int);
extern int nng_socket_set_size(nng_socket, const char *, size_t);
extern int nng_socket_set_uint64(nng_socket, const char *, uint64_t);
extern int nng_socket_set_string(nng_socket, const char *, const char *);
extern int nng_socket_set_ptr(nng_socket, const char *, void *);
extern int nng_socket_set_ms(nng_socket, const char *, nng_duration);
extern int nng_socket_set_addr(
    nng_socket, const char *, const nng_sockaddr *);
extern int nng_socket_get(nng_socket, const char *, void *, size_t *);
extern int nng_socket_get_bool(nng_socket, const char *, bool *);
extern int nng_socket_get_int(nng_socket, const char *, int *);
extern int nng_socket_get_size(nng_socket, const char *, size_t *);
extern int nng_socket_get_uint64(nng_socket, const char *, uint64_t *);
extern int nng_socket_get_string(nng_socket, const char *, char **);
extern int nng_socket_get_ptr(nng_socket, const char *, void **);
extern int nng_socket_get_ms(nng_socket, const char *, nng_duration *);
extern int nng_socket_get_addr(nng_socket, const char *, nng_sockaddr *);
typedef enum {
 NNG_PIPE_EV_ADD_PRE,
 NNG_PIPE_EV_ADD_POST,
 NNG_PIPE_EV_REM_POST,
 NNG_PIPE_EV_NUM,
} nng_pipe_ev;
typedef void (*nng_pipe_cb)(nng_pipe, nng_pipe_ev, void *);
extern int nng_pipe_notify(nng_socket, nng_pipe_ev, nng_pipe_cb, void *);
extern int nng_listen(nng_socket, const char *, nng_listener *, int);
extern int nng_dial(nng_socket, const char *, nng_dialer *, int);
extern int nng_dialer_create(nng_dialer *, nng_socket, const char *);
extern int nng_listener_create(nng_listener *, nng_socket, const char *);
extern int nng_dialer_start(nng_dialer, int);
extern int nng_listener_start(nng_listener, int);
extern int nng_dialer_close(nng_dialer);
extern int nng_listener_close(nng_listener);
extern int nng_dialer_id(nng_dialer);
extern int nng_listener_id(nng_listener);
extern int nng_dialer_set(nng_dialer, const char *, const void *, size_t);
extern int nng_dialer_set_bool(nng_dialer, const char *, bool);
extern int nng_dialer_set_int(nng_dialer, const char *, int);
extern int nng_dialer_set_size(nng_dialer, const char *, size_t);
extern int nng_dialer_set_uint64(nng_dialer, const char *, uint64_t);
extern int nng_dialer_set_string(nng_dialer, const char *, const char *);
extern int nng_dialer_set_ptr(nng_dialer, const char *, void *);
extern int nng_dialer_set_ms(nng_dialer, const char *, nng_duration);
extern int nng_dialer_set_addr(
    nng_dialer, const char *, const nng_sockaddr *);
extern int nng_dialer_get(nng_dialer, const char *, void *, size_t *);
extern int nng_dialer_get_bool(nng_dialer, const char *, bool *);
extern int nng_dialer_get_int(nng_dialer, const char *, int *);
extern int nng_dialer_get_size(nng_dialer, const char *, size_t *);
extern int nng_dialer_get_uint64(nng_dialer, const char *, uint64_t *);
extern int nng_dialer_get_string(nng_dialer, const char *, char **);
extern int nng_dialer_get_ptr(nng_dialer, const char *, void **);
extern int nng_dialer_get_ms(nng_dialer, const char *, nng_duration *);
extern int nng_dialer_get_addr(nng_dialer, const char *, nng_sockaddr *);
extern int nng_listener_set(
    nng_listener, const char *, const void *, size_t);
extern int nng_listener_set_bool(nng_listener, const char *, bool);
extern int nng_listener_set_int(nng_listener, const char *, int);
extern int nng_listener_set_size(nng_listener, const char *, size_t);
extern int nng_listener_set_uint64(nng_listener, const char *, uint64_t);
extern int nng_listener_set_string(nng_listener, const char *, const char *);
extern int nng_listener_set_ptr(nng_listener, const char *, void *);
extern int nng_listener_set_ms(nng_listener, const char *, nng_duration);
extern int nng_listener_set_addr(
    nng_listener, const char *, const nng_sockaddr *);
extern int nng_listener_get(nng_listener, const char *, void *, size_t *);
extern int nng_listener_get_bool(nng_listener, const char *, bool *);
extern int nng_listener_get_int(nng_listener, const char *, int *);
extern int nng_listener_get_size(nng_listener, const char *, size_t *);
extern int nng_listener_get_uint64(nng_listener, const char *, uint64_t *);
extern int nng_listener_get_string(nng_listener, const char *, char **);
extern int nng_listener_get_ptr(nng_listener, const char *, void **);
extern int nng_listener_get_ms(nng_listener, const char *, nng_duration *);
extern int nng_listener_get_addr(nng_listener, const char *, nng_sockaddr *);
extern const char *nng_strerror(int);
extern int nng_send(nng_socket, void *, size_t, int);
extern int nng_recv(nng_socket, void *, size_t *, int);
extern int nng_sendmsg(nng_socket, nng_msg *, int);
extern int nng_recvmsg(nng_socket, nng_msg **, int);
extern void nng_send_aio(nng_socket, nng_aio *);
extern void nng_recv_aio(nng_socket, nng_aio *);
extern int nng_ctx_open(nng_ctx *, nng_socket);
extern int nng_ctx_close(nng_ctx);
extern int nng_ctx_id(nng_ctx);
extern void nng_ctx_recv(nng_ctx, nng_aio *);
extern void nng_ctx_send(nng_ctx, nng_aio *);
extern int nng_ctx_get(nng_ctx, const char *, void *, size_t *);
extern int nng_ctx_get_bool(nng_ctx, const char *, bool *);
extern int nng_ctx_get_int(nng_ctx, const char *, int *);
extern int nng_ctx_get_size(nng_ctx, const char *, size_t *);
extern int nng_ctx_get_uint64(nng_ctx, const char *, uint64_t *);
extern int nng_ctx_get_string(nng_ctx, const char *, char **);
extern int nng_ctx_get_ptr(nng_ctx, const char *, void **);
extern int nng_ctx_get_ms(nng_ctx, const char *, nng_duration *);
extern int nng_ctx_get_addr(nng_ctx, const char *, nng_sockaddr *);
extern int nng_ctx_set(nng_ctx, const char *, const void *, size_t);
extern int nng_ctx_set_bool(nng_ctx, const char *, bool);
extern int nng_ctx_set_int(nng_ctx, const char *, int);
extern int nng_ctx_set_size(nng_ctx, const char *, size_t);
extern int nng_ctx_set_uint64(nng_ctx, const char *, uint64_t);
extern int nng_ctx_set_string(nng_ctx, const char *, const char *);
extern int nng_ctx_set_ptr(nng_ctx, const char *, void *);
extern int nng_ctx_set_ms(nng_ctx, const char *, nng_duration);
extern int nng_ctx_set_addr(nng_ctx, const char *, const nng_sockaddr *);
extern void *nng_alloc(size_t);
extern void nng_free(void *, size_t);
extern char *nng_strdup(const char *);
extern void nng_strfree(char *);
extern int nng_aio_alloc(nng_aio **, void (*)(void *), void *);
extern void nng_aio_free(nng_aio *);
extern void nng_aio_reap(nng_aio *);
extern void nng_aio_stop(nng_aio *);
extern int nng_aio_result(nng_aio *);
extern size_t nng_aio_count(nng_aio *);
extern void nng_aio_cancel(nng_aio *);
extern void nng_aio_abort(nng_aio *, int);
extern void nng_aio_wait(nng_aio *);
extern void nng_aio_set_msg(nng_aio *, nng_msg *);
extern nng_msg *nng_aio_get_msg(nng_aio *);
extern int nng_aio_set_input(nng_aio *, unsigned, void *);
extern void *nng_aio_get_input(nng_aio *, unsigned);
extern int nng_aio_set_output(nng_aio *, unsigned, void *);
extern void *nng_aio_get_output(nng_aio *, unsigned);
extern void nng_aio_set_timeout(nng_aio *, nng_duration);
extern int nng_aio_set_iov(nng_aio *, unsigned, const nng_iov *);
extern bool nng_aio_begin(nng_aio *);
extern void nng_aio_finish(nng_aio *, int);
typedef void (*nng_aio_cancelfn)(nng_aio *, void *, int);
extern void nng_aio_defer(nng_aio *, nng_aio_cancelfn, void *);
extern void nng_sleep_aio(nng_duration, nng_aio *);
extern int nng_msg_alloc(nng_msg **, size_t);
extern void nng_msg_free(nng_msg *);
extern int nng_msg_realloc(nng_msg *, size_t);
extern int nng_msg_reserve(nng_msg *, size_t);
extern size_t nng_msg_capacity(nng_msg *);
extern void * nng_msg_header(nng_msg *);
extern size_t nng_msg_header_len(const nng_msg *);
extern void * nng_msg_body(nng_msg *);
extern size_t nng_msg_len(const nng_msg *);
extern int nng_msg_append(nng_msg *, const void *, size_t);
extern int nng_msg_insert(nng_msg *, const void *, size_t);
extern int nng_msg_trim(nng_msg *, size_t);
extern int nng_msg_chop(nng_msg *, size_t);
extern int nng_msg_header_append(nng_msg *, const void *, size_t);
extern int nng_msg_header_insert(nng_msg *, const void *, size_t);
extern int nng_msg_header_trim(nng_msg *, size_t);
extern int nng_msg_header_chop(nng_msg *, size_t);
extern int nng_msg_header_append_u16(nng_msg *, uint16_t);
extern int nng_msg_header_append_u32(nng_msg *, uint32_t);
extern int nng_msg_header_append_u64(nng_msg *, uint64_t);
extern int nng_msg_header_insert_u16(nng_msg *, uint16_t);
extern int nng_msg_header_insert_u32(nng_msg *, uint32_t);
extern int nng_msg_header_insert_u64(nng_msg *, uint64_t);
extern int nng_msg_header_chop_u16(nng_msg *, uint16_t *);
extern int nng_msg_header_chop_u32(nng_msg *, uint32_t *);
extern int nng_msg_header_chop_u64(nng_msg *, uint64_t *);
extern int nng_msg_header_trim_u16(nng_msg *, uint16_t *);
extern int nng_msg_header_trim_u32(nng_msg *, uint32_t *);
extern int nng_msg_header_trim_u64(nng_msg *, uint64_t *);
extern int nng_msg_append_u16(nng_msg *, uint16_t);
extern int nng_msg_append_u32(nng_msg *, uint32_t);
extern int nng_msg_append_u64(nng_msg *, uint64_t);
extern int nng_msg_insert_u16(nng_msg *, uint16_t);
extern int nng_msg_insert_u32(nng_msg *, uint32_t);
extern int nng_msg_insert_u64(nng_msg *, uint64_t);
extern int nng_msg_chop_u16(nng_msg *, uint16_t *);
extern int nng_msg_chop_u32(nng_msg *, uint32_t *);
extern int nng_msg_chop_u64(nng_msg *, uint64_t *);
extern int nng_msg_trim_u16(nng_msg *, uint16_t *);
extern int nng_msg_trim_u32(nng_msg *, uint32_t *);
extern int nng_msg_trim_u64(nng_msg *, uint64_t *);
extern int nng_msg_dup(nng_msg **, const nng_msg *);
extern void nng_msg_clear(nng_msg *);
extern void nng_msg_header_clear(nng_msg *);
extern void nng_msg_set_pipe(nng_msg *, nng_pipe);
extern nng_pipe nng_msg_get_pipe(const nng_msg *);
extern int nng_pipe_get(nng_pipe, const char *, void *, size_t *);
extern int nng_pipe_get_bool(nng_pipe, const char *, bool *);
extern int nng_pipe_get_int(nng_pipe, const char *, int *);
extern int nng_pipe_get_ms(nng_pipe, const char *, nng_duration *);
extern int nng_pipe_get_size(nng_pipe, const char *, size_t *);
extern int nng_pipe_get_uint64(nng_pipe, const char *, uint64_t *);
extern int nng_pipe_get_string(nng_pipe, const char *, char **);
extern int nng_pipe_get_ptr(nng_pipe, const char *, void **);
extern int nng_pipe_get_addr(nng_pipe, const char *, nng_sockaddr *);
extern int nng_pipe_close(nng_pipe);
extern int nng_pipe_id(nng_pipe);
extern nng_socket nng_pipe_socket(nng_pipe);
extern nng_dialer nng_pipe_dialer(nng_pipe);
extern nng_listener nng_pipe_listener(nng_pipe);
extern int nng_stats_get(nng_stat **);
extern void nng_stats_free(nng_stat *);
extern void nng_stats_dump(nng_stat *);
extern nng_stat *nng_stat_next(nng_stat *);
extern nng_stat *nng_stat_child(nng_stat *);
extern const char *nng_stat_name(nng_stat *);
extern int nng_stat_type(nng_stat *);
extern nng_stat *nng_stat_find(nng_stat *, const char *);
extern nng_stat *nng_stat_find_socket(nng_stat *, nng_socket);
extern nng_stat *nng_stat_find_dialer(nng_stat *, nng_dialer);
extern nng_stat *nng_stat_find_listener(nng_stat *, nng_listener);
enum nng_stat_type_enum {
 NNG_STAT_SCOPE = 0,
 NNG_STAT_LEVEL = 1,
 NNG_STAT_COUNTER = 2,
 NNG_STAT_STRING = 3,
 NNG_STAT_BOOLEAN = 4,
 NNG_STAT_ID = 5,
};
extern int nng_stat_unit(nng_stat *);
enum nng_unit_enum {
 NNG_UNIT_NONE = 0,
 NNG_UNIT_BYTES = 1,
 NNG_UNIT_MESSAGES = 2,
 NNG_UNIT_MILLIS = 3,
 NNG_UNIT_EVENTS = 4
};
extern uint64_t nng_stat_value(nng_stat *);
extern bool nng_stat_bool(nng_stat *);
extern const char *nng_stat_string(nng_stat *);
extern const char *nng_stat_desc(nng_stat *);
extern uint64_t nng_stat_timestamp(nng_stat *);
extern int nng_device(nng_socket, nng_socket);
enum nng_errno_enum {
 NNG_EINTR = 1,
 NNG_ENOMEM = 2,
 NNG_EINVAL = 3,
 NNG_EBUSY = 4,
 NNG_ETIMEDOUT = 5,
 NNG_ECONNREFUSED = 6,
 NNG_ECLOSED = 7,
 NNG_EAGAIN = 8,
 NNG_ENOTSUP = 9,
 NNG_EADDRINUSE = 10,
 NNG_ESTATE = 11,
 NNG_ENOENT = 12,
 NNG_EPROTO = 13,
 NNG_EUNREACHABLE = 14,
 NNG_EADDRINVAL = 15,
 NNG_EPERM = 16,
 NNG_EMSGSIZE = 17,
 NNG_ECONNABORTED = 18,
 NNG_ECONNRESET = 19,
 NNG_ECANCELED = 20,
 NNG_ENOFILES = 21,
 NNG_ENOSPC = 22,
 NNG_EEXIST = 23,
 NNG_EREADONLY = 24,
 NNG_EWRITEONLY = 25,
 NNG_ECRYPTO = 26,
 NNG_EPEERAUTH = 27,
 NNG_ENOARG = 28,
 NNG_EAMBIGUOUS = 29,
 NNG_EBADTYPE = 30,
 NNG_ECONNSHUT = 31,
 NNG_EINTERNAL = 1000,
 NNG_ESYSERR = 0x10000000,
 NNG_ETRANERR = 0x20000000
};
typedef struct nng_url {
 char *u_rawurl;
 char *u_scheme;
 char *u_userinfo;
 char *u_host;
 char *u_hostname;
 char *u_port;
 char *u_path;
 char *u_query;
 char *u_fragment;
 char *u_requri;
} nng_url;
extern int nng_url_parse(nng_url **, const char *);
extern void nng_url_free(nng_url *);
extern int nng_url_clone(nng_url **, const nng_url *);
extern const char *nng_version(void);
typedef struct nng_stream nng_stream;
typedef struct nng_stream_dialer nng_stream_dialer;
typedef struct nng_stream_listener nng_stream_listener;
extern void nng_stream_free(nng_stream *);
extern void nng_stream_close(nng_stream *);
extern void nng_stream_send(nng_stream *, nng_aio *);
extern void nng_stream_recv(nng_stream *, nng_aio *);
extern int nng_stream_get(nng_stream *, const char *, void *, size_t *);
extern int nng_stream_get_bool(nng_stream *, const char *, bool *);
extern int nng_stream_get_int(nng_stream *, const char *, int *);
extern int nng_stream_get_ms(nng_stream *, const char *, nng_duration *);
extern int nng_stream_get_size(nng_stream *, const char *, size_t *);
extern int nng_stream_get_uint64(nng_stream *, const char *, uint64_t *);
extern int nng_stream_get_string(nng_stream *, const char *, char **);
extern int nng_stream_get_ptr(nng_stream *, const char *, void **);
extern int nng_stream_get_addr(nng_stream *, const char *, nng_sockaddr *);
extern int nng_stream_set(nng_stream *, const char *, const void *, size_t);
extern int nng_stream_set_bool(nng_stream *, const char *, bool);
extern int nng_stream_set_int(nng_stream *, const char *, int);
extern int nng_stream_set_ms(nng_stream *, const char *, nng_duration);
extern int nng_stream_set_size(nng_stream *, const char *, size_t);
extern int nng_stream_set_uint64(nng_stream *, const char *, uint64_t);
extern int nng_stream_set_string(nng_stream *, const char *, const char *);
extern int nng_stream_set_ptr(nng_stream *, const char *, void *);
extern int nng_stream_set_addr(
     nng_stream *, const char *, const nng_sockaddr *);
extern int nng_stream_dialer_alloc(nng_stream_dialer **, const char *);
extern int nng_stream_dialer_alloc_url(
    nng_stream_dialer **, const nng_url *);
extern void nng_stream_dialer_free(nng_stream_dialer *);
extern void nng_stream_dialer_close(nng_stream_dialer *);
extern void nng_stream_dialer_dial(nng_stream_dialer *, nng_aio *);
extern int nng_stream_dialer_set(
     nng_stream_dialer *, const char *, const void *, size_t);
extern int nng_stream_dialer_get(
    nng_stream_dialer *, const char *, void *, size_t *);
extern int nng_stream_dialer_get_bool(
    nng_stream_dialer *, const char *, bool *);
extern int nng_stream_dialer_get_int(
    nng_stream_dialer *, const char *, int *);
extern int nng_stream_dialer_get_ms(
    nng_stream_dialer *, const char *, nng_duration *);
extern int nng_stream_dialer_get_size(
    nng_stream_dialer *, const char *, size_t *);
extern int nng_stream_dialer_get_uint64(
    nng_stream_dialer *, const char *, uint64_t *);
extern int nng_stream_dialer_get_string(
    nng_stream_dialer *, const char *, char **);
extern int nng_stream_dialer_get_ptr(
    nng_stream_dialer *, const char *, void **);
extern int nng_stream_dialer_get_addr(
    nng_stream_dialer *, const char *, nng_sockaddr *);
extern int nng_stream_dialer_set_bool(
    nng_stream_dialer *, const char *, bool);
extern int nng_stream_dialer_set_int(nng_stream_dialer *, const char *, int);
extern int nng_stream_dialer_set_ms(
    nng_stream_dialer *, const char *, nng_duration);
extern int nng_stream_dialer_set_size(
    nng_stream_dialer *, const char *, size_t);
extern int nng_stream_dialer_set_uint64(
    nng_stream_dialer *, const char *, uint64_t);
extern int nng_stream_dialer_set_string(
    nng_stream_dialer *, const char *, const char *);
extern int nng_stream_dialer_set_ptr(
    nng_stream_dialer *, const char *, void *);
extern int nng_stream_dialer_set_addr(
    nng_stream_dialer *, const char *, const nng_sockaddr *);
extern int nng_stream_listener_alloc(nng_stream_listener **, const char *);
extern int nng_stream_listener_alloc_url(
    nng_stream_listener **, const nng_url *);
extern void nng_stream_listener_free(nng_stream_listener *);
extern void nng_stream_listener_close(nng_stream_listener *);
extern int nng_stream_listener_listen(nng_stream_listener *);
extern void nng_stream_listener_accept(nng_stream_listener *, nng_aio *);
extern int nng_stream_listener_set(
     nng_stream_listener *, const char *, const void *, size_t);
extern int nng_stream_listener_get(
    nng_stream_listener *, const char *, void *, size_t *);
extern int nng_stream_listener_get_bool(
    nng_stream_listener *, const char *, bool *);
extern int nng_stream_listener_get_int(
    nng_stream_listener *, const char *, int *);
extern int nng_stream_listener_get_ms(
    nng_stream_listener *, const char *, nng_duration *);
extern int nng_stream_listener_get_size(
    nng_stream_listener *, const char *, size_t *);
extern int nng_stream_listener_get_uint64(
    nng_stream_listener *, const char *, uint64_t *);
extern int nng_stream_listener_get_string(
    nng_stream_listener *, const char *, char **);
extern int nng_stream_listener_get_ptr(
    nng_stream_listener *, const char *, void **);
extern int nng_stream_listener_get_addr(
    nng_stream_listener *, const char *, nng_sockaddr *);
extern int nng_stream_listener_set_bool(
    nng_stream_listener *, const char *, bool);
extern int nng_stream_listener_set_int(
    nng_stream_listener *, const char *, int);
extern int nng_stream_listener_set_ms(
    nng_stream_listener *, const char *, nng_duration);
extern int nng_stream_listener_set_size(
    nng_stream_listener *, const char *, size_t);
extern int nng_stream_listener_set_uint64(
    nng_stream_listener *, const char *, uint64_t);
extern int nng_stream_listener_set_string(
    nng_stream_listener *, const char *, const char *);
extern int nng_stream_listener_set_ptr(
    nng_stream_listener *, const char *, void *);
extern int nng_stream_listener_set_addr(
    nng_stream_listener *, const char *, const nng_sockaddr *);
int nng_bus0_open(nng_socket *);
int nng_bus0_open_raw(nng_socket *);
int nng_pair0_open(nng_socket *);
int nng_pair0_open_raw(nng_socket *);
int nng_pair1_open(nng_socket *);
int nng_pair1_open_raw(nng_socket *);
int nng_pair1_open_poly(nng_socket *);
int nng_push0_open(nng_socket *);
int nng_push0_open_raw(nng_socket *);
int nng_pull0_open(nng_socket *);
int nng_pull0_open_raw(nng_socket *);
int nng_pub0_open(nng_socket *);
int nng_pub0_open_raw(nng_socket *);
int nng_sub0_open(nng_socket *);
int nng_sub0_open_raw(nng_socket *);
int nng_req0_open(nng_socket *);
int nng_req0_open_raw(nng_socket *);
int nng_rep0_open(nng_socket *);
int nng_rep0_open_raw(nng_socket *);
int nng_surveyor0_open(nng_socket *);
int nng_surveyor0_open_raw(nng_socket *);
int nng_respondent0_open(nng_socket *);
int nng_respondent0_open_raw(nng_socket *);
typedef struct nng_tls_config nng_tls_config;
typedef enum nng_tls_mode {
 NNG_TLS_MODE_CLIENT = 0,
 NNG_TLS_MODE_SERVER = 1,
} nng_tls_mode;
typedef enum nng_tls_auth_mode {
 NNG_TLS_AUTH_MODE_NONE = 0,
 NNG_TLS_AUTH_MODE_OPTIONAL = 1,
 NNG_TLS_AUTH_MODE_REQUIRED = 2,
} nng_tls_auth_mode;
typedef enum nng_tls_version {
 NNG_TLS_1_0 = 0x301,
 NNG_TLS_1_1 = 0x302,
 NNG_TLS_1_2 = 0x303,
 NNG_TLS_1_3 = 0x304
} nng_tls_version;
int nng_tls_config_alloc(nng_tls_config **, nng_tls_mode);
void nng_tls_config_hold(nng_tls_config *);
void nng_tls_config_free(nng_tls_config *);
int nng_tls_config_server_name(nng_tls_config *, const char *);
int nng_tls_config_ca_chain(
    nng_tls_config *, const char *, const char *);
int nng_tls_config_own_cert(
    nng_tls_config *, const char *, const char *, const char *);
int nng_tls_config_auth_mode(nng_tls_config *, nng_tls_auth_mode);
int nng_tls_config_ca_file(nng_tls_config *, const char *);
int nng_tls_config_cert_key_file(
    nng_tls_config *, const char *, const char *);
int nng_tls_config_version(
    nng_tls_config *, nng_tls_version, nng_tls_version);
const char *nng_tls_engine_name(void);
const char *nng_tls_engine_description(void);
bool nng_tls_engine_fips_mode(void);
#define NNG_FLAG_ALLOC 1u // Recv to allocate receive buffer
#define NNG_FLAG_NONBLOCK 2u // Non-blocking operations
#define NNG_MAJOR_VERSION 1
#define NNG_MINOR_VERSION 5
#define NNG_PATCH_VERSION 2
