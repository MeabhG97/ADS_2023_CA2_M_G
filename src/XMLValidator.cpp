#include "XMLValidator.hpp"

bool XMLValidator::validateXML(vector<string> file) {
    stack<string> tags;
    bool emptied = false;

    for (string line : file) {
        // Check if line contains closing tag
        if (line.find("/") != string::npos) {
            int tagStart = line.find_first_not_of("<");
            if (tagStart == string::npos) {
                continue;
            }

            // Closing tage only on line
            if (line.at(tagStart) == '/') {
                tagStart += 1;
                int tagEnd = line.find_last_of(">");
                int tagRange = tagEnd - tagStart + 1;
                string tag = line.substr(tagStart, tagRange - 1);

                if (tags.empty()) {
                    return false;
                }

                if (tag != tags.top()) {
                    return false;
                }

                tags.pop();

                if (tags.empty()) {
                    emptied = true;
                }
                continue;
            }

            // Opening and closing on line
            // Opening tag
            int tagEnd = line.find_first_of(">");
            int tagRange = tagEnd - tagStart + 1;
            string tag = line.substr(tagStart, tagRange - 1);

            if (emptied) {
                return false;
            }
            tags.push(tag);

            line = line.substr(tagEnd + 1);
            // cout << line << endl;

            // Closing tag
            tagStart = line.find_first_of("<");
            if (tagStart == string::npos) {
                continue;
            }

            if (line.at(tagStart + 1) != '/') {
                continue;
            }
            tagStart += 2;

            tagEnd = line.find_last_of(">");
            tagRange = tagEnd - tagStart + 1;
            tag = line.substr(tagStart, tagRange - 1);

            if (tags.empty()) {
                return false;
            }

            if (tag != tags.top()) {
                return false;
            }

            tags.pop();

            if (tags.empty()) {
                emptied = true;
            }

            continue;
        }

        // Opening tag only on line
        const int tagStart = line.find_first_not_of("<");
        if (tagStart == string::npos) {
            continue;
        }

        const int tagEnd = line.find_last_of(">");

        // Add tag name to stack
        string tag = line.substr(tagStart, tagEnd - 1);

        if (emptied) {
            return false;
        }
        tags.push(tag);
    }

    if (tags.size() != 0) {
        return false;
    }

    if(!emptied){
        return false;
    }

    return true;
}