#ifndef BUTIL_STATE_CONT_SERVICE_H
#define BUTIL_STATE_CONT_SERVICE_H
#include "butil/state_cont/counter_rpc.pb.h"
#include "butil/endpoint.h"
// #define LOG_MACRO_STATE_CONT VLOG(79) 
#define LOG_MACRO_STATE_CONT LOG(INFO) 
namespace butil {
class StateContServiceImpl : public StateContService {
public:
    explicit StateContServiceImpl(butil::EndPoint addr)
        : _addr(addr) {}
    ~StateContServiceImpl();

    void pre_inc_counter(google::protobuf::RpcController* controller,
                              const PreIncCounterReq* request,
                              PreIncCounterResp* response,
                              google::protobuf::Closure* done);
    
    void confirm_inc_counter(google::protobuf::RpcController* controller,
                              const PreIncCounterReq* request,
                              PreIncCounterResp* response,
                              google::protobuf::Closure* done);

    void store_states(google::protobuf::RpcController* controller,
                              const StateStoreRequest* request,
                              StateContinuityResp* response,
                              google::protobuf::Closure* done);

    // void retrieve_states(google::protobuf::RpcController* controller,
    //                           const StateStoreRequest* request,
    //                           StateContinuityResp* response,
    //                           google::protobuf::Closure* done);
    void test_connectable(google::protobuf::RpcController* controller,
                              const TestConnectRequest* request,
                              StateContinuityResp* response,
                              google::protobuf::Closure* done);
private:
    butil::EndPoint _addr;
    void _print_pre_inc_request(const PreIncCounterReq* request);
};

}

#endif //BUTIL_STATE_CONT_SERVICE_H