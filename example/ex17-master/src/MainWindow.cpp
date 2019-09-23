#include "MainWindow.hpp"
#include "AboutDialog.hpp"

MainWindow::MainWindow(QWidget * parent, Qt::WindowFlags flags): 
  QMainWindow(parent, flags) {

  // this line has to be the first thing here.
  // It creates the GUI from the .ui file
  setupUi(this);
}

MainWindow::~MainWindow() {
}

// menu bar actions

void MainWindow::on_quit_action_triggered() {
  close();
  QApplication::quit();
}

void MainWindow::on_about_action_triggered() {
  AboutDialog dialog(this);
  dialog.exec();
}

// buttons
void MainWindow::on_number0Button_clicked() {
  displayTextEdit->insertPlainText(QString("0"));
}

void MainWindow::on_number1Button_clicked() {
  displayTextEdit->insertPlainText(QString("1"));
}

void MainWindow::on_number2Button_clicked() {
  displayTextEdit->insertPlainText(QString("2"));
}

void MainWindow::on_number3Button_clicked() {
  displayTextEdit->insertPlainText(QString("3"));
}

void MainWindow::on_number4Button_clicked() {
  displayTextEdit->insertPlainText(QString("4"));
}

void MainWindow::on_number5Button_clicked() {
  displayTextEdit->insertPlainText(QString("5"));
}

void MainWindow::on_number6Button_clicked() {
  displayTextEdit->insertPlainText(QString("6"));
}

void MainWindow::on_number7Button_clicked() {
  displayTextEdit->insertPlainText(QString("7"));
}

void MainWindow::on_number8Button_clicked() {
  displayTextEdit->insertPlainText(QString("8"));
}

void MainWindow::on_number9Button_clicked() {
  displayTextEdit->insertPlainText(QString("9"));
}

void MainWindow::on_addButton_clicked() {
  displayTextEdit->insertPlainText(QString("+"));
}

void MainWindow::on_subtractButton_clicked() {
  displayTextEdit->insertPlainText(QString("-"));
}

void MainWindow::on_multiplyButton_clicked() {
  displayTextEdit->insertPlainText(QString("*"));
}

void MainWindow::on_divideButton_clicked() {
  displayTextEdit->insertPlainText(QString("/"));
}

void MainWindow::on_leftParenButton_clicked() {
  displayTextEdit->insertPlainText(QString("("));
}

void MainWindow::on_rightParenButton_clicked() {
  displayTextEdit->insertPlainText(QString(")"));
}

void MainWindow::on_decimalPointButton_clicked() {
  displayTextEdit->insertPlainText(QString("."));
}

void MainWindow::on_changeSignButton_clicked() {
  // get current expression
  QString qStr = displayTextEdit->toPlainText();

  // if (string == "") {
  //   append '-'
  // } else {
  //   if(last character of string == '+')
  //     replace last character by '-'
  //   else if(last character of string == '-')
  //     replace last character by '+'
  //   else
  //     append '-'
  // }

  int nChars = qStr.size();
  if(nChars==0) {
    qStr = "-";
  } else /* if(nChars>0) */ {
    QString qFront = qStr.left(nChars-1);
    QString qLast  = qStr.right(1);
    if(qLast=="+")
      qStr = qFront + "-";
    else if(qLast=="-")
      qStr = qFront + "+";
    else
      qStr += "-";
  }

  // display the edited expression
  displayTextEdit->clear();
  displayTextEdit->insertPlainText(qStr);
}

void MainWindow::on_clearButton_clicked() {
  displayTextEdit->clear();
  QString qStr = "<font color=\"black\"></font>";
  displayTextEdit->insertHtml(qStr);
}

void MainWindow::on_evaluateButton_clicked() {
  // get current expression
  QString qStr = displayTextEdit->toPlainText();

  // convert to C-style string
  QByteArray array = qStr.toLocal8Bit();
  char* cExprString = array.data();
  // or
  // std::string cPPstr = qStr.toStdString();
  // const char* cStr = cPPstr.c_str();

  // create AlgebraicTreeExpression
  AlgebraicTreeExpression expr(cExprString);
  unsigned exprLength   = qStr.size();
  unsigned parsedLength = expr.getParsedLength();
  bool parsingError     = expr.getParsingError();

  // if (parser fails to parse the current expression) {
  if(parsingError || parsedLength<exprLength) {
    // get length of initial parsed substring
    // display the same expression with the initial
    // parsed expression painted in black and the rest in red
    QString qStrParsed    = qStr.left(parsedLength);
    QString qStrNotParsed = qStr.right(exprLength-parsedLength); 

    // build an html string
    qStr =
      "<font color=\"black\">" + qStrParsed    + "</font>"+
      "<font color=\"red\">"   + qStrNotParsed + "</font>";

    // clear the display and show the result
    displayTextEdit->clear();
    displayTextEdit->insertHtml(qStr);

  } else /* if(parser succeeds) */ {
    
    // evaluate
    double value = expr.evaluate();
    // convert result to QString
    // clear the display
    displayTextEdit->clear();
    // display the result
    qStr.setNum(value);

    // displayTextEdit->insertPlainText(qStr);
    qStr = "<font color=\"black\">" + qStr+ "</font>";
    displayTextEdit->insertHtml(qStr);
    
    // optional
    // - allocate the root node in the heap
    //   and save it in a circular list
    // - add buttons to retrieve previous expressions
    // - and others to remove expressions from the list
    // - make sure that you don't save duplicate expressions in the list

  }

}
