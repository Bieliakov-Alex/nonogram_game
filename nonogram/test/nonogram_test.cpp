/*Copyright 2020 Alex Bieliakov*/

#include "mock_nonogram_log.hpp"
#include "nonogram.hpp"

#include "gtest/gtest.h"

using ::testing::NiceMock;

TEST(NonogramTest, GetRowsTest) {
  std::vector<std::vector<uint8_t>> r, empty_columns;
  std::vector<uint8_t> r_1{1, 2, 3, 4};
  r.push_back(r_1);
  auto nonogram =
      Nonogram(r, empty_columns, std::make_shared<NiceMock<MockNonogramLog>>());
  EXPECT_EQ(nonogram.GetRows(), 1);

  // Empty rows
  std::vector<std::vector<uint8_t>> empty_rows;
  auto empty_nonogram = Nonogram(empty_rows, empty_columns,
                                 std::make_shared<NiceMock<MockNonogramLog>>());
  EXPECT_EQ(empty_nonogram.GetRows(), 0);

  // 10 rows
  std::vector<std::vector<uint8_t>> rows_10;
  for (uint8_t i = 0; i < 10; ++i) {
    rows_10.push_back(std::vector<uint8_t>());
  }
  auto nonogram_10_rows = Nonogram(
      rows_10, empty_columns, std::make_shared<NiceMock<MockNonogramLog>>());
  EXPECT_EQ(nonogram_10_rows.GetRows(), 10);
}

TEST(NonogramTest, GetColumnsTest) {
  std::vector<std::vector<uint8_t>> empty_rows, empty_columns, columns_1,
      columns_10;
  columns_1.push_back(std::vector<uint8_t>());
  for (uint8_t i = 0; i < 10; ++i) {
    columns_10.push_back(std::vector<uint8_t>());
  }

  auto empty_nonogram = Nonogram(empty_rows, empty_columns,
                                 std::make_shared<NiceMock<MockNonogramLog>>());
  auto nonogram_1 = Nonogram(empty_rows, columns_1,
                             std::make_shared<NiceMock<MockNonogramLog>>());
  auto nonogram_10 = Nonogram(empty_rows, columns_10,
                              std::make_shared<NiceMock<MockNonogramLog>>());

  EXPECT_EQ(empty_nonogram.GetColumns(), 0);
  EXPECT_EQ(nonogram_1.GetColumns(), 1);
  EXPECT_EQ(nonogram_10.GetColumns(), 10);
}

TEST(NonogramTest, GetRowNumbersTest) {
  std::vector<std::vector<uint8_t>> empty_columns, rows;

  // Test empty rows.
  auto empty_nonogram = Nonogram(rows, empty_columns,
                                 std::make_shared<NiceMock<MockNonogramLog>>());
  EXPECT_THROW(empty_nonogram.GetRowNumbers(0), std::runtime_error);

  // Test one entry rows.
  rows.push_back(std::vector<uint8_t>({1, 2, 3, 4}));
  auto one_entry_nonogram = Nonogram(
      rows, empty_columns, std::make_shared<NiceMock<MockNonogramLog>>());
  EXPECT_EQ(one_entry_nonogram.GetRowNumbers(0),
            std::vector<uint8_t>({1, 2, 3, 4}));

  // Test many entry rows.
  rows.push_back(std::vector<uint8_t>({5, 6, 7, 8}));
  auto many_entry_nonogram = Nonogram(
      rows, empty_columns, std::make_shared<NiceMock<MockNonogramLog>>());
  EXPECT_NE(many_entry_nonogram.GetRowNumbers(1),
            std::vector<uint8_t>({1, 2, 3, 4}));
  EXPECT_EQ(many_entry_nonogram.GetRowNumbers(1),
            std::vector<uint8_t>({5, 6, 7, 8}));
}

TEST(NonogramTest, GetColumnNumbersTest) {
  std::vector<std::vector<uint8_t>> columns, empty_rows;

  // Test empty columns.
  auto empty_nonogram = Nonogram(empty_rows, columns,
                                 std::make_shared<NiceMock<MockNonogramLog>>());
  EXPECT_THROW(empty_nonogram.GetColumnNumbers(0), std::runtime_error);

  // Test one entry rows.
  columns.push_back(std::vector<uint8_t>({1, 2, 3, 4}));
  auto one_entry_nonogram = Nonogram(
      empty_rows, columns, std::make_shared<NiceMock<MockNonogramLog>>());
  EXPECT_EQ(one_entry_nonogram.GetColumnNumbers(0),
            std::vector<uint8_t>({1, 2, 3, 4}));

  // Test many entry rows.
  columns.push_back(std::vector<uint8_t>({5, 6, 7, 8}));
  auto many_entry_nonogram = Nonogram(
      empty_rows, columns, std::make_shared<NiceMock<MockNonogramLog>>());
  EXPECT_NE(many_entry_nonogram.GetColumnNumbers(1),
            std::vector<uint8_t>({1, 2, 3, 4}));
  EXPECT_EQ(many_entry_nonogram.GetColumnNumbers(1),
            std::vector<uint8_t>({5, 6, 7, 8}));
}

TEST(NonogramTest, GetFieldTest) {
  // Test empty field
  std::vector<std::vector<uint8_t>> empty_rows, empty_columns;
  auto empty_nonogram = Nonogram(empty_rows, empty_columns,
                                 std::make_shared<NiceMock<MockNonogramLog>>());
  auto empty_field = std::vector<std::vector<NonogramCellState>>();
  EXPECT_EQ(empty_nonogram.GetField(), empty_field);

  // Test nonempty field
  std::vector<std::vector<uint8_t>> nonempty_rows{{1}}, nonempty_columns{{1}};
  auto nonempty_nonogram =
      Nonogram(nonempty_rows, nonempty_columns,
               std::make_shared<NiceMock<MockNonogramLog>>());
  nonempty_nonogram.SetNonogramCellState(0, 0, NonogramCellState::kMarked);
  EXPECT_EQ(nonempty_nonogram.GetField()[0][0], NonogramCellState::kMarked);
}

TEST(NonogramTest, GetNonogramCellStateTest) {
  // Test throw
  std::vector<std::vector<uint8_t>> empty_rows, empty_columns;
  auto empty_nonogram = Nonogram(empty_rows, empty_columns,
                                 std::make_shared<NiceMock<MockNonogramLog>>());
  EXPECT_THROW(empty_nonogram.GetNonogramCellState(0, 0), std::runtime_error);

  // Test correct state
  std::vector<std::vector<uint8_t>> nonempty_rows{{1}}, nonempty_columns{{1}};
  auto nonempty_nonogram =
      Nonogram(nonempty_rows, nonempty_columns,
               std::make_shared<NiceMock<MockNonogramLog>>());
  nonempty_nonogram.SetNonogramCellState(0, 0, NonogramCellState::kMarked);
  EXPECT_EQ(nonempty_nonogram.GetNonogramCellState(0, 0),
            NonogramCellState::kMarked);
  nonempty_nonogram.SetNonogramCellState(0, 0, NonogramCellState::kCrossed);
  EXPECT_EQ(nonempty_nonogram.GetNonogramCellState(0, 0),
            NonogramCellState::kCrossed);
  nonempty_nonogram.SetNonogramCellState(0, 0, NonogramCellState::kEmpty);
  EXPECT_EQ(nonempty_nonogram.GetNonogramCellState(0, 0),
            NonogramCellState::kEmpty);
}

TEST(NonogramTest, SetNonogramCellStateTest) {
  // Test throw
  std::vector<std::vector<uint8_t>> empty_rows, empty_columns;
  auto empty_nonogram = Nonogram(empty_rows, empty_columns,
                                 std::make_shared<NiceMock<MockNonogramLog>>());
  EXPECT_THROW(
      empty_nonogram.SetNonogramCellState(0, 0, NonogramCellState::kMarked),
      std::runtime_error);

  // Test correct state
  std::vector<std::vector<uint8_t>> nonempty_rows{{1}}, nonempty_columns{{1}};
  auto nonempty_nonogram =
      Nonogram(nonempty_rows, nonempty_columns,
               std::make_shared<NiceMock<MockNonogramLog>>());
  nonempty_nonogram.SetNonogramCellState(0, 0, NonogramCellState::kMarked);
  EXPECT_EQ(nonempty_nonogram.GetNonogramCellState(0, 0),
            NonogramCellState::kMarked);
  nonempty_nonogram.SetNonogramCellState(0, 0, NonogramCellState::kCrossed);
  EXPECT_EQ(nonempty_nonogram.GetNonogramCellState(0, 0),
            NonogramCellState::kCrossed);
  nonempty_nonogram.SetNonogramCellState(0, 0, NonogramCellState::kEmpty);
  EXPECT_EQ(nonempty_nonogram.GetNonogramCellState(0, 0),
            NonogramCellState::kEmpty);
}
