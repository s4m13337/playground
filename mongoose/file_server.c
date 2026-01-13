#include "mongoose.h"

typedef struct mg_connection mg_conn;
typedef struct mg_http_message mg_http_msg;
typedef struct mg_http_serve_opts mg_http_serve_opts;
typedef struct mg_mgr mg_mgr;

void ev_handler(mg_conn* c, int ev, void* ev_data) {
  if(ev == MG_EV_HTTP_MSG){
    mg_http_msg* hm = (mg_http_msg*) ev_data;
    mg_http_serve_opts opts = { .root_dir = "./web_root" };
    mg_http_serve_dir(c, hm, &opts);
  }
}

int main() {
  mg_mgr mgr;
  mg_mgr_init(&mgr);
  mg_http_listen(&mgr, "http://localhost:55432", ev_handler, NULL);
  while(1){
    mg_mgr_poll(&mgr, 10000);
  }
  return 0;
}
