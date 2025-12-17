#include "FFeedback.h"
#include <stdexcept>

namespace model {

FFeedback::FFeedback(std::string feedbackId, std::string orderId, std::string menuId)
    : feedbackId_(std::move(feedbackId)), orderId_(std::move(orderId)), menuId_(std::move(menuId)) {}

static void validateRating(int rating) {
    if (rating < 1 || rating > 5) throw std::out_of_range("rating must be between 1 and 5");
}

void FFeedback::addFeedback(int rating, const std::string& comment) {
    validateRating(rating);
    rating_ = rating;
    content_ = comment;
    // Example mapping: score = rating * 20
    score_ = rating_ * 20;
}

void FFeedback::updateFeedback(int rating, const std::string& comment) {
    addFeedback(rating, comment);
}

void FFeedback::addReply(const std::string& replyText) {
    reply_ = replyText;
}

const std::string& FFeedback::getFeedbackId() const { return feedbackId_; }
const std::string& FFeedback::getOrderId() const { return orderId_; }
const std::string& FFeedback::getMenuId() const { return menuId_; }
int FFeedback::getRating() const { return rating_; }
int FFeedback::getScore() const { return score_; }
const std::string& FFeedback::getContent() const { return content_; }
std::optional<std::string> FFeedback::getReply() const { return reply_; }

} // namespace model
