// hw02.cpp : Defines the entry point for the application.
//

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]

using namespace std;


auto split(const auto& str, auto d)
{
    std::vector<std::string> r;
    auto start = 0;
    auto stop = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }
    r.push_back(str.substr(start));
    return r;
}

void print_vec(const std::vector<size_t> &ip) {
    for (std::vector<size_t>::const_iterator ip_part = ip.cbegin(); ip_part != ip.cend(); ++ip_part)
    {
        if (ip_part != ip.cbegin())
        {
            std::cout << ".";

        }
        std::cout << *ip_part;
    }
    std::cout << std::endl;
}

int main(int argc, char const* argv[])
{
    try
    {
        std::vector<std::vector<size_t> > ip_pool;

        for (std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            std::vector<std::string> v_ip = split(v.at(0), '.');
            std::vector<size_t> v_ip_transf;

            std::transform(v_ip.begin(), v_ip.end(), std::back_inserter(v_ip_transf),
                [](const std::string& str) { return std::stoi(str); });
            ip_pool.push_back(v_ip_transf);
        }

        std::sort(ip_pool.begin(), ip_pool.end(), 
            [](const std::vector<size_t>& a, const std::vector<size_t>& b) {
                return std::lexicographical_compare(b.begin(), b.end(), a.begin(), a.end());
            });

        int shift_cond_1 = -1;
        std::vector<std::vector<size_t>> condition_2;
        std::vector<std::vector<size_t>> condition_3;


        for (std::vector<std::vector<size_t>>::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
        {
            if (((*ip)[0] == 1) && (shift_cond_1 == -1)) {
                shift_cond_1 = ip - ip_pool.cbegin();
            }
            
            if (((*ip)[0] == 46) && ((*ip)[1] == 70)) {
                condition_2.push_back(*ip);
            }

            auto it = std::find(begin(*ip), end(*ip), 46);
            if (it != end(*ip)) {
                condition_3.push_back(*ip);
            }
            
            print_vec(*ip);
        }

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        for (std::vector<std::vector<size_t>>::const_iterator ip = ip_pool.cbegin() + shift_cond_1; ip != ip_pool.cend(); ++ip)
        {
            print_vec(*ip);
        }

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        for (std::vector<std::vector<size_t>>::const_iterator ip = condition_2.cbegin(); ip != condition_2.cend(); ++ip)
        {
            print_vec(*ip);
        }

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        for (std::vector<std::vector<size_t>>::const_iterator ip = condition_3.cbegin(); ip != condition_3.cend(); ++ip)
        {
            print_vec(*ip);
        }

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
