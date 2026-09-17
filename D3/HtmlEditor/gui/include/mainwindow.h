#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/// @brief Главное окно HTML-редактора с предпросмотром через QWebEngineView
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
    /// @brief Обработчик изменения текста в левом поле.
    /// Полностью перестраивает HTML-представление справа.
    void OnTextChanged();

private:
    Ui::MainWindow *ui_; ///< Указатель на сгенерированный интерфейс
};
