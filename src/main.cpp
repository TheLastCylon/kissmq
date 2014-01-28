// kissmq : A message broker that uses the kisscpp library.
// Author : Dirk J. Botha <bothadj@gmail.com>

#include "kissmq.hpp"

int main(int argc, char* argv[])
{
  try {
    kissmq app;
    app.run();
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}

