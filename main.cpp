#include <cstdlib>
#include <iostream>
#include <json/json.h> // or something
#include <memory>
#include <restbed>
#include <string>

using namespace std;
using namespace restbed;

void delete_method_handler(const shared_ptr<Session> session) {
  const auto request = session->get_request();

  std::string destination = request->get_path_parameter("collection_id");

  std::cout << "Destination on DELETE is " << destination << std::endl;
}

void post_method_handler(const shared_ptr<Session> session) {
  const auto request = session->get_request();

  size_t content_length = request->get_header("Content-Length", 0);

  Json::Value ch;
  ch["collection_id"] = 3;

  std::stringstream response;

  response << ch;

  session->close(
      OK, response.str(),
      {{"Content-Length", std::to_string(response.str().length()).c_str()},
       {"Connection", "close"}});
}

int main(const int, const char **) {
  auto post_resource = make_shared<Resource>();
  Service service;

  post_resource->set_path("/collections");
  post_resource->set_method_handler("POST", post_method_handler);

  service.publish(post_resource);

  auto delete_resource = make_shared<Resource>();
  delete_resource->set_method_handler("DELETE", delete_method_handler);
  delete_resource->set_path("/collections/{collection_id: .*}");

  service.publish(delete_resource);
  service.start();

  return EXIT_SUCCESS;
}
