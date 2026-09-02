#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <include/swimmer.h>

int main()
{
    const int swimmerCount = 6;
    std::vector<Swimmer*> swimmers;
    std::vector<std::thread> threads;

    std::cout << "Enter names and speeds (m/s) for 6 swimmers: " << std::endl;
    for (int i = 0; i < swimmerCount; ++i)
    {
        std::string name;
        double speed;
        std::cout << "Swimmer " << i + 1 << ": ";
        std::cin >> name >> speed;
        swimmers.push_back(new Swimmer(name, speed));
    }

    for (auto* s : swimmers)
    {
        threads.emplace_back(&Swimmer::StartSwim, s);
    }

    while (!Swimmer::AllFinished(swimmers))
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        Swimmer::PrintCurrentStatus(swimmers);
    }

    for (auto& t : threads)
    {
        t.join();
    }

    std::sort(swimmers.begin(), swimmers.end(),
              [](Swimmer* a, Swimmer* b)
              {
                  return a->GetTime() < b->GetTime();
              });

    std::cout << "\nFinal results:\n";
    for (const auto* s : swimmers)
    {
        std::cout << s->GetName() << ": " << std::fixed << std::setprecision(2)
                  << s->GetTime() << " s\n";
    }

    for (auto* s : swimmers)
    {
        delete s;
    }

    return 0;
}
