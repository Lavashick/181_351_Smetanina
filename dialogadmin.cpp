#include "dialogadmin.h"
#include "ui_dialogadmin.h"
#include "dialog.h"
#include "dialogeditusers.h"
#include <QStandardItemModel>


Dialog *hoziain;

DialogAdmin::DialogAdmin(QWidget *parent,  QByteArray degree, QTcpSocket *clientSocketOfParent) :
    QDialog(parent),
    ui(new Ui::DialogAdmin)
{
    ui->setupUi(this);
    hoziain = (Dialog*)parent;
    connect(parent,SIGNAL(goToDialogAdmin(QByteArray array)),this,SLOT(readDialogAdmin(QByteArray array)));

    clientSocket = clientSocketOfParent;
    degreeOfUser = degree.toInt();

    // Админ
    if (degreeOfUser == 1)
    {
        ui->frameYesNo->hide();
        ui->frameYesNo ->hide();
        ui->frameAddUsers->hide();
        ui->frameStarpers->hide();
        ui->frameEditUsers->hide();
        ui->frameAddStarpers->hide();
        ui->frameEditStarpers->hide();
        send_to_server("select&*&users");
    }
    else if (degreeOfUser == 2)
    {
        ui->frameYesNo->hide();
        ui->frameAddUsers->hide();
        ui->frameUsers->hide();
        ui->frameEditUsers->hide();
        ui->frameAddStarpers->hide();
        ui->frameEditStarpers->hide();
        send_to_server("select&*&starpers");
    }

    // Создание таблицы


    /*
    if (degreeOfUser == 1)
    {
        model = new QStandardItemModel(5, 2, this);
        ui->tableView->setModel(model);
    }
    */
    /*model = new QStandardItemModel(5, 2, this);
    ui->tableView->setModel(model);
    parent->hide();*/

}

DialogAdmin::~DialogAdmin()
{
    delete ui;
}

void DialogAdmin::configure() {
    switch (user->degree) {
    //
    case 1:
        ui->pushButton->setText("Edit table of users");
        break;
    case 2:
        ui->pushButton->setText("Edit this table");
        break;
    case 3:
        ui->pushButton->hide();
        break;
    default:
        break;
    }
}

// Закрытие текущего окна
void DialogAdmin::on_pushButton_7_clicked()
{
    this->hide();
    this->user = nullptr;
    hoziain->resetPasswordField();
    hoziain->show();
}


// Открытие нового окна
void DialogAdmin::on_pushButton_clicked()
{
    DialogEditUsers* window = new DialogEditUsers(this);
    window->setModal(true);
    if (ui->pushButton->text() == "Edit table of users")
        window->exec();
}

void DialogAdmin::on_refreshTable_clicked()
{
   if(degreeOfUser == 1)
   {
       send_to_server("select&*&users");
   }
   else {
       send_to_server("select&*&starpers");
   }
}

void DialogAdmin::send_to_server(QString message)
{
    QByteArray array; // шо это говно делает. мы не можем отправить данные  чисто в строке
    // общение у нас происходит на кубайтарраевском. потому что это байтовые массивы нулей и единиц, короче вот так вот.
    //эта маленькая функция автоматизирует процесс отправки серверу всего дерьма, что нужно ему отправить
    array.append(message);
    clientSocket->write(array);// то что мы отправляем. в виде Qstring
    // теперь он всегда знает куда отправлять те пакеты говна что мы называем данными
}

void DialogAdmin::readDialogAdmin(QByteArray array)
{
    QList <QByteArray> shit = array.split('&');
    if (shit[0] == "select")
    {
        selectAnswer(shit);
    }

}
void DialogAdmin::selectAnswer(QList <QByteArray> shit){

    int n = shit[1].toInt();
    tableDB = new QStandardItemModel(0, n, this);
    // Разрешаем выделение строк
    ui->tableDB->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableDB->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableDB->textElideMode();

    QStandardItem *item;
    ui->tableDB->setModel(tableDB);
    for (int i = 0; i < n; i++){
        tableDB->setHeaderData(i, Qt::Horizontal, shit[i+2]);
    }
    int m =0;
    int k = 0;
    for (int i = 0; i < (shit.size()-n-2)/*число именно записей*/; i++) {
        if (i>0){
            if (i%n==0){ // подсчет количества строк в таблице
                k+=1;
        }
        }
        item = new QStandardItem(QString::fromStdString(shit[i+2+n].toStdString()));
        if (m == shit[1].toInt()){ // m не больше трех, т.к. это позиционирование элемента в строке
            m = 0;
        }
        tableDB->setItem(k, m, item); // строка, столбец, элемент (данные)
        m++;
    }
}
