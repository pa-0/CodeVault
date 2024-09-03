#pragma once 
#include <string>




class CodeSnippetModel {
private:
    int snippet_id;
    std::string snippet_name;
    std::string snippet_data;
    int language_id;
    int user_id;
    std::string snippet_description;

public:
    // Constructor
    CodeSnippetModel(int id, const std::string& name, const std::string& data, int langId, int userId, const std::string& description)
        : snippet_id(id), snippet_name(name), snippet_data(data), language_id(langId), user_id(userId), snippet_description(description) {}

    // Inline Getters and Setters
    int getSnippetId() const { return snippet_id; }
    void setSnippetId(int id) { snippet_id = id; }

    std::string getSnippetName() const { return snippet_name; }
    void setSnippetName(const std::string& name) { snippet_name = name; }

    std::string getSnippetData() const { return snippet_data; }
    void setSnippetData(const std::string& data) { snippet_data = data; }

    int getLanguageId() const { return language_id; }
    void setLanguageId(int langId) { language_id = langId; }

    int getUserId() const { return user_id; }
    void setUserId(int userId) { user_id = userId; }

    std::string getSnippetDescription() const { return snippet_description; }
    void setSnippetDescription(const std::string& description) { snippet_description = description; }
};