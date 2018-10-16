#include <QWidget>
#include <QtCharts/QPieSeries>
#include "sysinfo.h"
#include "sysinfowidget.h"
#include "cpuwidget.h"

using namespace QtCharts;

CpuWidget::CpuWidget(QWidget* parent):
    SysInfoWidget(parent),
    mSeries(new QPieSeries(this)),
	mLoad(nullptr),
	mFree(nullptr)
{
    mSeries->setHoleSize(0.35);
    mLoad = mSeries->append("CPU Load", 30.0);
    mFree = mSeries->append("CPU Free", 70.0);

    QChart* chart = chartView().chart();
	QFont tFont = chart->titleFont();
	tFont.setBold(true);

	chart->setTitleFont(tFont);
	chart->addSeries(mSeries);	
    chart->setTitle("CPU average load");
	chart->setAnimationOptions(QChart::SeriesAnimations);
}


void CpuWidget::updateSeries()
{
	double cpuLoadAverage = SysInfo::instance().cpuLoadAverage();		
	mLoad->setValue(cpuLoadAverage);	
	mFree->setValue(100.0 - cpuLoadAverage);	
}
