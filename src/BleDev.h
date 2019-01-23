#ifndef BLEDEV_H
#define BLEDEV_H

#include <QWidget>

class WSClient;

namespace Ui {
class BleDev;
}

class BleDev : public QWidget
{
    Q_OBJECT

public:
    explicit BleDev(QWidget *parent = nullptr);
    ~BleDev();

    void setWsClient(WSClient *c);
    void clearWidgets();

private slots:
    void on_btnFileBrowser_clicked();

    void on_btnPlatInfo_clicked();

    void displayPlatInfoReceived(int auxMajor, int auxMinor, int mainMajor, int mainMinor);

    void displayUploadBundleResultReceived(bool success);
    
    void on_btnReflashAuxMCU_clicked();
    
    void on_btnFlashMainMCU_clicked();

    void on_btnUpload_clicked();

private:
    void initUITexts();


    WSClient *wsClient = nullptr;
    Ui::BleDev *ui;
};

#endif // BLEDEV_H
