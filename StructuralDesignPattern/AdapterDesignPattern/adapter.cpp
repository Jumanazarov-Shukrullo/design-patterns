#include <iostream>

class XMLData {
    std::string m_data;
public:
    explicit XMLData(std::string xml_data) : m_data(std::move(xml_data)) {}

    [[nodiscard]] std::string get_data() const { return m_data; }
};

class DataAnalyticsTool {
std::string m_data;
public:
    DataAnalyticsTool() = default;
    explicit DataAnalyticsTool(std::string json_data): m_data(std::move(json_data)) {}

    virtual void analyse() {
        std::cout << "analysing data: " << m_data << "\n";
    }
};

class Adapter : public DataAnalyticsTool {
XMLData* data;
public:
    explicit Adapter(XMLData* xmlData): data(xmlData) {

    }
    void analyse() override {
        std::cout << "overriding data: " << data->get_data() << "\n";
    }
};

class Client {
public:
    static void process_data(DataAnalyticsTool* tool) {
        tool->analyse();
    }
};
int main() {
    auto* xmlData = new XMLData("Xml Data");
    DataAnalyticsTool* tool = new Adapter(xmlData);
    Client::process_data(tool);
    return 0;
}