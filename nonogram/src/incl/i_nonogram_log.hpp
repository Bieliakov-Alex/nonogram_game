/*Copyright 2020 Alex Bieliakov*/

#ifndef NONOGRAM_GAME_NONOGRAM_SRC_INCL_I_NONOGRAM_HPP_
#define NONOGRAM_GAME_NONOGRAM_SRC_INCL_I_NONOGRAM_HPP_

#include <string>

/**
 * @brief The purpose of the interface is to wrapp the logging system and
 * symplify changing and mocking it.
 */
class INonogramLog {
public:
  virtual ~INonogramLog() = default;
  /**
   * @brief The method logs on info level.
   *
   * @param log_message The message string that should be logged.
   */
  virtual void LogInfo(const std::string &log_message) const = 0;
};

#endif // NONOGRAM_GAME_NONOGRAM_SRC_INCL_I_NONOGRAM_HPP_
