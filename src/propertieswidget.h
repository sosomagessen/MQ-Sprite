#ifndef PROPERTIESWIDGET_H
#define PROPERTIESWIDGET_H

#include <QColor>
#include <QWidget>
class QLabel;
class QTextEdit;
class PartWidget;

namespace Ui {
class PropertiesWidget;
}

class PropertiesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PropertiesWidget(QWidget *parent = nullptr);
    ~PropertiesWidget();

	PartWidget* targetPartWidget();
	void setTargetPartWidget(PartWidget* p); // if p is null then no target widget

public slots:
	void textPropertiesEdited();
	void targetPartPropertiesChanged();

private:
	void setProperties(const QString& properties);

private:
    Ui::PropertiesWidget *ui = nullptr;
	PartWidget* mTarget = nullptr;
	QString mCurrentMode {};
	QTextEdit* mTextEditProperties = nullptr;
	QLabel* mLabelParseStatus = nullptr;
	QColor mDefaultTextEditColour;
};

#endif // PROPERTIESWIDGET_H
