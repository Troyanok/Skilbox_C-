#pragma once

#include <QMainWindow>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/// @brief Главное окно приложения для наложения Blur-эффекта на картинку
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
    /// @brief Открывает диалог выбора картинки и загружает её
    void OnOpenImage();

    /// @brief Реагирует на изменение значения слайдера
    /// @param value Новое значение слайдера (0..10)
    void OnSliderValueChanged(int value);

private:
    /// @brief Применяет Blur с текущим значением слайдера и обновляет QLabel
    void UpdateImage();

    Ui::MainWindow *ui_;   ///< Указатель на сгенерированный интерфейс
    QImage sourceImage_;   ///< Исходное изображение
};
