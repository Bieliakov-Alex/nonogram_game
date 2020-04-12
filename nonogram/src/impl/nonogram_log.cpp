/*Copyright 2020 Alex Bieliakov*/

#include "nonogram_log.hpp"

#include <boost/log/trivial.hpp>

void NonogramLog::LogInfo(const std::string &log_message) const {
  BOOST_LOG_TRIVIAL(info) << log_message;
}
