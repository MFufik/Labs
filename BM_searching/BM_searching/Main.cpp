#include <iostream>
#include <string>
#include <vector>

// Индекс первого вхождения подстроки
size_t findFirstOccurrence(const std::string& text, const std::string& pattern) {
    return text.find(pattern);
}

//Индексы всех вхождений подстроки
std::vector<int> findAllOccurrences(const std::string& text, const std::string& pattern) {
    std::vector<int> occurrences;
    size_t pos = text.find(pattern, 0);
    while (pos != std::string::npos) {
        occurrences.push_back(pos);
        pos = text.find(pattern, pos + 1);
    }
    return occurrences;
}

// Индексы всех вхождений подстроки в заданном диапазоне
std::vector<int> findOccurrencesInRange(const std::string& text, const std::string& pattern, size_t start, size_t end) {
    std::vector<int> occurrences;
    if (start > end || end > text.length() || start >= text.length()) return occurrences; // Обработка некорректного диапазона

    size_t pos = text.find(pattern, start);
    while (pos != std::string::npos && pos <= end) { 
        occurrences.push_back(pos);
        pos = text.find(pattern, pos + 1);
    }
    return occurrences;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string text, pattern;
    size_t start, end;

    std::cout << "Введите текст: ";
    std::getline(std::cin, text); // для чтения строки 

    std::cout << "Введите подстроку для поиска: ";
    std::getline(std::cin, pattern);

    std::cout << "Введите начало диапазона поиска (включительно): ";
    std::cin >> start;

    std::cout << "Введите конец диапазона поиска (включительно): ";
    std::cin >> end;


    size_t firstOccurrence = findFirstOccurrence(text, pattern);
    std::cout << "\nИндекс первого вхождения: " << firstOccurrence << std::endl;

    std::vector<int> allOccurrences = findAllOccurrences(text, pattern);
    std::cout << "Индексы всех вхождений: ";
    for (int index : allOccurrences) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    std::vector<int> occurrencesInRange = findOccurrencesInRange(text, pattern, start, end);
    std::cout << "Индексы вхождений в диапазоне [" << start << ", " << end << "]: ";
    for (int index : occurrencesInRange) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}