/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

// This autogenerated skeleton file illustrates how to build an
// asynchronous server. You should copy it to another filename to
// avoid overwriting it.

#include "thrift/compiler/test/fixtures/basic-cpp-async/gen-cpp/MyService.h"
#include <thrift/lib/cpp/async/TEventServer.h>
#include <thrift/lib/cpp/util/TEventServerCreator.h>

using apache::thrift::async::TAsyncProcessor;
using apache::thrift::async::TEventServer;
using apache::thrift::util::TEventServerCreator;

using std::shared_ptr;

using namespace  ;

class MyServiceAsyncHandler : public MyServiceCobSvIf {
 public:
  MyServiceAsyncHandler() {
    // Your initialization goes here
  }
  virtual ~MyServiceAsyncHandler() {}

  void ping(std::function<void()> cob) {
    // Your implementation goes here.
    // You can also schedule an async operation, and invoke
    // the callback later once the operation completes,
    // rather than invoking it before returning here.
    printf("ping\n");
    cob();
  }

  void getRandomData(std::function<void(std::string const& _return)> cob) {
    std::string _return;
    // Your implementation goes here.
    // You can also schedule an async operation, and invoke
    // the callback later once the operation completes,
    // rather than invoking it before returning here.
    printf("getRandomData\n");
    cob(_return);
  }

  void hasDataById(std::function<void(bool const& _return)> cob, int64_t id) {
    bool _return = false;
    // Your implementation goes here.
    // You can also schedule an async operation, and invoke
    // the callback later once the operation completes,
    // rather than invoking it before returning here.
    printf("hasDataById\n");
    cob(_return);
  }

  void getDataById(std::function<void(std::string const& _return)> cob, int64_t id) {
    std::string _return;
    // Your implementation goes here.
    // You can also schedule an async operation, and invoke
    // the callback later once the operation completes,
    // rather than invoking it before returning here.
    printf("getDataById\n");
    cob(_return);
  }

  void putDataById(std::function<void()> cob, int64_t id, const std::string& data) {
    // Your implementation goes here.
    // You can also schedule an async operation, and invoke
    // the callback later once the operation completes,
    // rather than invoking it before returning here.
    printf("putDataById\n");
    cob();
  }

  void lobDataById(std::function<void()> cob, int64_t id, const std::string& data) {
    // Your implementation goes here.
    // You can also schedule an async operation, and invoke
    // the callback later once the operation completes,
    // rather than invoking it before returning here.
    printf("lobDataById\n");
    cob();
  }

  void putStructById(std::function<void()> cob, int64_t id, const MyStruct& data) {
    // Your implementation goes here.
    // You can also schedule an async operation, and invoke
    // the callback later once the operation completes,
    // rather than invoking it before returning here.
    printf("putStructById\n");
    cob();
  }
};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<MyServiceAsyncHandler> handler(new MyServiceAsyncHandler());
  shared_ptr<TAsyncProcessor> processor(new MyServiceAsyncProcessor(handler));
  TEventServerCreator serverCreator(processor, port);
  shared_ptr<TEventServer> server = serverCreator.createEventServer();
  server->serve();
  return 0;
}
