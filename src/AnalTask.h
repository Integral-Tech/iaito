#ifndef ANALTHREAD_H
#define ANALTHREAD_H

#include "utils/AsyncTask.h"
#include "Cutter.h"

class CutterCore;
class MainWindow;
class OptionsDialog;

struct InitialOptions
{
	enum class Endianness { Auto, Little, Big };

	QString filename;

	bool useVA = true;
	RVA binLoadAddr = RVA_INVALID;
	RVA mapAddr = RVA_INVALID;

	QString arch;
	QString cpu;
	int bits = 0;
	QString os;

	Endianness endian;

	bool writeEnabled = false;
	bool loadBinInfo = true;
	QString forceBinPlugin;

	bool demangle = true;

	QString pdbFile;
	QString script;

	int bbsize = 0;

	int analLevel = 1;
	QList<QString> analAdvanced;
};

class AnalTask : public AsyncTask
{
    Q_OBJECT

public:
    explicit AnalTask(QObject *parent = nullptr);
    ~AnalTask();

    QString getTitle() override                     { return tr("Initial Analysis"); }

    void setOptions(const InitialOptions &options)	{ this->options = options; }

    void interrupt() override;
    void interruptAndWait();

protected:
    void runTask() override;

signals:
    void openFileFailed();

private:
    InitialOptions options;
};

#endif // ANALTHREAD_H