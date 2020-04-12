/*Copyright 2020 Alex Bieliakov*/

#include "nonogram_factory.hpp"

#include <boost/log/trivial.hpp>

#include "nonogram.hpp"
#include "nonogram_log.hpp"

std::shared_ptr<INonogram>
MakeNonogram(const std::vector<std::vector<uint8_t>> &row_numbers,
             const std::vector<std::vector<uint8_t>> &column_numbers) {
  return std::make_shared<Nonogram>(row_numbers, column_numbers,
                                    std::make_shared<NonogramLog>());
}
