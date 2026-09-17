#pragma once

#include <QMainWindow>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/// @brief Главное окно с красной кнопкой, воспроизводящей звук при нажатии
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// @brief Конструктор главного окна
    /// @param parent Родительский виджет
    explicit MainWindow(QWidget *parent = nullptr);

    /// @brief Деструктор
    ~MainWindow() override;

private slots:
    /// @brief Обработчик нажатия на красную кнопку.
    /// Воспроизводит звук щелчка.
    void OnButtonPressed();

private:
    Ui::MainWindow *ui_;   ///< Указатель на сгенерированный интерфейс
    QMediaPlayer *player_; ///< Проигрыватель звука нажатия
};
