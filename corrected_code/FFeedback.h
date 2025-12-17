#ifndef FFEEDBACK_H
#define FFEEDBACK_H

#include <string>
#include <optional>
#include <chrono>

namespace model {

class FFeedback {
public:
    FFeedback() = default;
    FFeedback(std::string feedbackId, std::string orderId, std::string menuId);

    void addFeedback(int rating, const std::string& comment);
    void updateFeedback(int rating, const std::string& comment);
    void addReply(const std::string& replyText);

    // Read
    const std::string& getFeedbackId() const;
    const std::string& getOrderId() const;
    const std::string& getMenuId() const;
    int getRating() const;
    int getScore() const;
    const std::string& getContent() const;
    std::optional<std::string> getReply() const;

private:
    std::string feedbackId_;
    std::string orderId_;
    std::string menuId_;

    int rating_ = 0; // e.g., 1-5
    int score_ = 0;  // you can define what "score" means in your system
    std::string content_;
    std::chrono::system_clock::time_point time_ = std::chrono::system_clock::now();
    std::optional<std::string> reply_;
};

} // namespace model

#endif // FFEEDBACK_H
