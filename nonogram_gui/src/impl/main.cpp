/*Copyright 2020 Alex Bieliakov*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <cstdint>
#include <vector>

#include "column_numbers_model.hpp"
#include "nonogram_factory.hpp"
#include "nonogram_field_model.hpp"
#include "nonogram_rect_model.hpp"
#include "nonogram_wrapper.hpp"
#include "row_numbers_model.hpp"

int main(int argc, char *argv[]) {
  std::vector<std::vector<uint8_t>> row_numbers({{4, 3, 6},
                                                 {2, 1, 2, 2, 1, 2},
                                                 {2, 1, 2, 1, 3, 1, 3, 2},
                                                 {1, 2, 2, 4, 2, 1},
                                                 {1, 2, 2, 1, 1, 3, 1},
                                                 {1, 3, 1, 2, 1, 1, 1},
                                                 {1, 1, 1, 2, 2, 1},
                                                 {2, 2, 6, 2, 2},
                                                 {2, 2, 1, 1, 2, 2},
                                                 {5, 3, 3, 6}}),
      column_numbers(
          {{6},          {2, 2},       {2, 2},    {1, 1, 1}, {1, 1, 3, 1},
           {1, 1, 1, 1}, {2, 3, 3},    {1, 1, 1}, {5},       {1, 2, 1},
           {3, 2},       {1, 1, 1, 1}, {1, 2, 2}, {1, 1, 2}, {6, 1, 1},
           {1, 2, 2},    {3},          {1, 1, 1}, {3, 2},    {1, 5, 1},
           {1, 4},       {1, 1},       {2, 2},    {2, 2},    {6}});
  auto nonogram = MakeNonogram(row_numbers, column_numbers);
  NonogramWrapper nonogram_wrapper(nonogram);

  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  qmlRegisterType<NonogramRectModel>("NonogramModel", 1, 0,
                                     "NonogramRectModel");
  qmlRegisterType<ColumnNumbersModel>("NonogramModel", 1, 0,
                                      "ColumnNumbersModel");
  qmlRegisterType<RowNumbersModel>("NonogramModel", 1, 0, "RowNumbersModel");
  qmlRegisterType<NonogramFieldModel>("NonogramModel", 1, 0,
                                      "NonogramFieldModel");
  qmlRegisterUncreatableType<NonogramWrapper>(
      "NonogramModel", 1, 0, "NonogramWrapper",
      QStringLiteral("NonogramWrapper should not be created in QML"));

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty(QStringLiteral("nonogramWrapper"),
                                           &nonogram_wrapper);
  engine.load(QUrl(QLatin1String("qrc:resources/main.qml")));
  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  return app.exec();
}
