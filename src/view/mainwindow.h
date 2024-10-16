#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;  // Forward declaration of the UI class for MainWindow
}
QT_END_NAMESPACE

/**
 * @brief The MainWindow class represents the main application window.
 *
 * This class inherits from QMainWindow and serves as the central interface for
 * the application, providing access to various functionalities and features.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a MainWindow object.
     *
     * @param parent The parent widget (default is nullptr).
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor for the MainWindow class.
     *
     * Cleans up resources used by the MainWindow.
     */
    ~MainWindow();

private:
    Ui::MainWindow *ui;  /**< Pointer to the UI elements defined in the MainWindow UI file */
};

#endif // MAINWINDOW_H
