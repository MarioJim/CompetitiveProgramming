#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int numCities, numVacancies, tempInput;
    cin >> numCities >> numVacancies;

    auto compareFunc = [](const pair<int, int> pair1, const pair<int, int> pair2) {
        return pair1.first == pair2.first ? pair1.second < pair2.second : pair1.first < pair2.first;
    };
    multiset<pair<int, int>, decltype(compareFunc), allocator<pair<int, int>>>
            vacancies(compareFunc), candidates(compareFunc);
    for (int i = 0; i < numVacancies; ++i) {
        cin >> tempInput;
        vacancies.insert(pair(tempInput, i + 1));
    }
    for (int i = 0; i < numVacancies; ++i) {
        cin >> tempInput;
        candidates.insert(pair(tempInput, i + 1));
    }

    auto vacanciesIter = vacancies.begin(), candidatesIter = candidates.begin(); // Iterators for each set
    int first = min(vacanciesIter->first, candidatesIter->first), // First filled spot
        last = max((--vacancies.end())->first, (--candidates.end())->first), // Last filled spot
        begin = first, end = first, // Begin and end of greatest space
        past, next = first; // Past and next filled spot
    while (vacanciesIter != --vacancies.end() || candidatesIter != --candidates.end()) {
        if (vacanciesIter->first < candidatesIter->first) {
            if (vacanciesIter != --vacancies.end()) {
                past = next;
                ++vacanciesIter;
                next = min(vacanciesIter->first, candidatesIter->first);
            } else {
                past = candidatesIter->first;
                ++candidatesIter;
                next = candidatesIter->first;
            }
        } else {
            if (candidatesIter != --candidates.end()) {
                past = next;
                ++candidatesIter;
                next = min(vacanciesIter->first, candidatesIter->first);
            } else {
                past = vacanciesIter->first;
                ++vacanciesIter;
                next = vacanciesIter->first;
            }
        }
        if (next - past > end - begin) {
            begin = past;
            end = next;
        }
    }
    // Check if the greatest space is between last and first
    if (first + numCities - last > end - begin) {
        begin = first + numCities;
        end = last;
    }
    vacanciesIter = vacancies.begin(), candidatesIter = candidates.begin(); // Iterators for each set
    // Move iterators to first after begin
    while (vacanciesIter->first < end) {
        ++vacanciesIter;
        if (vacanciesIter == vacancies.end()) {
            vacanciesIter = vacancies.begin();
            break;
        }
    }
    while (candidatesIter->first < end) {
        ++candidatesIter;
        if (candidatesIter == candidates.end()) {
            candidatesIter = candidates.begin();
            break;
        }
    }
    // Save the sum in a long long
    long long sum = 0;
    // Save the results in an array
    int results[numVacancies + 1];
    for (int i = 0; i < numVacancies; ++i) {
        if (vacanciesIter == vacancies.end()) vacanciesIter = vacancies.begin();
        if (candidatesIter == candidates.end()) candidatesIter = candidates.begin();
        results[vacanciesIter->second] = candidatesIter->second;
        int possibleSum1 = numCities
                + min(vacanciesIter->first, candidatesIter->first)
                - max(vacanciesIter->first, candidatesIter->first);
        int possibleSum2 = abs(vacanciesIter->first - candidatesIter->first);
        sum += min(possibleSum1, possibleSum2);
        ++vacanciesIter; ++candidatesIter;
    }

    // Print sum
    cout << sum << "\n";
    // Print starting from first element in both starting in last
    for (int i = 1; i <= numVacancies; ++i) cout << results[i] << " ";

    return 0;
}