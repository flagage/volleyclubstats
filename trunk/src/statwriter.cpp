#include "statwriter.h"

statWriter::statWriter(Joueur player)
{
       m_document = new QTextDocument();
       m_cursor = QTextCursor(m_document);
       _player=player;
       QTextCharFormat defaultFormat;
       defaultFormat.setFontPointSize(12);
       boldFormat = defaultFormat;
       boldFormat.setFontWeight(QFont::Bold);
       QTextCharFormat titleFormat = boldFormat;
       titleFormat.setFontPointSize(20);

       centerFormat.setAlignment(Qt::AlignHCenter);

       m_cursor.setBlockFormat(centerFormat);
       m_cursor.insertText(QString("Analyse du joueur %1\n").arg(player.get_Prenom()),
                           titleFormat);

       QTextTableFormat tableFormat;
       tableFormat.setCellPadding(5);
       tableFormat.setHeaderRowCount(1);
       tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
       tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 100));

       m_cursor.insertTable(1, 5, tableFormat);
       m_cursor.insertText("nombre de points marqué", boldFormat);
       m_cursor.movePosition(QTextCursor::NextCell);
       m_cursor.insertText("efficacite recep", boldFormat);
       m_cursor.movePosition(QTextCursor::NextCell);
       m_cursor.insertText("efficacite service", boldFormat);
       m_cursor.movePosition(QTextCursor::NextCell);
       m_cursor.insertText("efficacite defence", boldFormat);
       m_cursor.movePosition(QTextCursor::NextCell);
       m_cursor.insertText("efficacite attaque", boldFormat);
}
statWriter::~statWriter()
{
    delete m_document;
}

void statWriter::addstat()
{
    QTextTable *table = m_cursor.currentTable();
    int NPM=_player.getStatMatch(0,0)+_player.getStatMatch(5,0);
       if (! table)
           return;

       table->appendRows(1); // moves our cursor to the end of the doc...
       m_cursor.movePosition(QTextCursor::PreviousRow);
       m_cursor.movePosition(QTextCursor::NextCell);
       m_cursor.insertText(QString::number(NPM));
       m_cursor.movePosition(QTextCursor::NextCell);
       m_cursor.insertText(QString::number(10));
       m_cursor.movePosition(QTextCursor::NextCell);

      // QChar euro(0x20ac);
     //  m_cursor.insertText(QString("%1 %2").arg(euro).arg(call.cost / (double) 100, 0, 'f', 2));
}

void statWriter::write(const QString &fileName)
{
    QTextDocumentWriter writer(fileName);
    writer.write(m_document);
}
