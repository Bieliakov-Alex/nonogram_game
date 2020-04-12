/*Copyright 2020 Alex Bieliakov*/

#ifndef NONOGRAM_GAME_NONOGRAM_SRC_INCL_NONOGRAM_LOG_HPP_
#define NONOGRAM_GAME_NONOGRAM_SRC_INCL_NONOGRAM_LOG_HPP_

#include <string>

#include "i_nonogram_log.hpp"

/**
 * @brief The implementation of the nonogram_log class
 */

class NonogramLog : public INonogramLog {
public:
  NonogramLog() = default;
  void LogInfo(const std::string &log_message) const override;
};

#endif // NONOGRAM_GAME_NONOGRAM_SRC_INCL_NONOGRAM_LOG_HPP_
