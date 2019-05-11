#include "staff.h"
#include "ui_staff.h"

Staff::Staff(QWidget *parent, int id) :
    QDialog(parent),
    ui(new Ui::Staff)
{
    ui->setupUi(this);

    // set the staff `id`
    this->id = id;

    // the query table
    model = new QSqlQueryModel();
}

Staff::~Staff()
{
    delete ui;
}

void Staff::on_pushButton_run_clicked()
{
    QString command = ui->command->toPlainText();
    QSqlQuery query;
    query.prepare(command);
    if (query.exec()) {
        ui->output_note->setPlainText("Query successful!");
        model->setQuery(query);

        // finally set the model for tableView
        ui->tableView->setModel(model);
    } else {
        ui->output_note->setPlainText("Query failed.");
    }
}

void Staff::on_pushButton_logout_clicked()
{
    hide();
    parentWidget()->show();
    delete ui;
}
