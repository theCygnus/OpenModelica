/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-2014, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR
 * THIS OSMC PUBLIC LICENSE (OSMC-PL) VERSION 1.2.
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3,
 * ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */
/*
 *
 * @author Adeel Asghar <adeel.asghar@liu.se>
 *
 *
 */

#ifndef SIMULATIONDIALOG_H
#define SIMULATIONDIALOG_H

#include "MainWindow.h"
#include "SimulationOptions.h"

class SimulationOutputWidget;

class ArchivedSimulationItem : public QTreeWidgetItem
{
public:
  ArchivedSimulationItem(SimulationOptions simulationOptions, SimulationOutputWidget *pSimulationOutputWidget)
    : mpSimulationOutputWidget(pSimulationOutputWidget)
  {
    setText(0, simulationOptions.getClassName());
    setToolTip(0, simulationOptions.getClassName());
    setText(1, QDateTime::currentDateTime().toString());
    setToolTip(1, QDateTime::currentDateTime().toString());
    setText(2, simulationOptions.getStartTime());
    setToolTip(2, simulationOptions.getStartTime());
    setText(3, simulationOptions.getStopTime());
    setToolTip(3, simulationOptions.getStopTime());
    setStatus(Helper::running);
  }
  SimulationOutputWidget* getSimulationOutputWidget() {return mpSimulationOutputWidget;}
  void setStatus(QString status) {
    setText(4, status);
    setToolTip(4, status);
  }
private:
  SimulationOutputWidget *mpSimulationOutputWidget;
};

class MainWindow;
class SimulationDialog : public QDialog
{
  Q_OBJECT
public:
  SimulationDialog(MainWindow *pParent = 0);
  ~SimulationDialog();
  QTreeWidget* getArchivedSimulationsTreeWidget() {return mpArchivedSimulationsTreeWidget;}
  void show(LibraryTreeItem *pLibraryTreeItem, bool isReSimulate, SimulationOptions simulationOptions);
  void directSimulate(LibraryTreeItem *pLibraryTreeItem, bool launchTransformationalDebugger, bool launchAlgorithmicDebugger);
private:
  MainWindow *mpMainWindow;
  Label *mpSimulationHeading;
  QFrame *mpHorizontalLine;
  QTabWidget *mpSimulationTabWidget;
  // General Tab
  QWidget *mpGeneralTab;
  QGroupBox *mpSimulationIntervalGroupBox;
  Label *mpStartTimeLabel;
  QLineEdit *mpStartTimeTextBox;
  Label *mpStopTimeLabel;
  QLineEdit *mpStopTimeTextBox;
  QRadioButton *mpNumberofIntervalsRadioButton;
  QSpinBox *mpNumberofIntervalsSpinBox;
  QRadioButton *mpIntervalRadioButton;
  QLineEdit *mpIntervalTextBox;
  QGroupBox *mpIntegrationGroupBox;
  Label *mpMethodLabel;
  QComboBox *mpMethodComboBox;
  QToolButton *mpMehtodHelpButton;
  Label *mpToleranceLabel;
  QLineEdit *mpToleranceTextBox;
  Label *mpJacobianLabel;
  QComboBox *mpJacobianComboBox;
  QGroupBox *mpDasslOptionsGroupBox;
  QCheckBox *mpDasslRootFindingCheckBox;
  QCheckBox *mpDasslRestartCheckBox;
  Label *mpDasslInitialStepSizeLabel;
  QLineEdit *mpDasslInitialStepSizeTextBox;
  Label *mpDasslMaxStepSizeLabel;
  QLineEdit *mpDasslMaxStepSizeTextBox;
  Label *mpDasslMaxIntegrationOrderLabel;
  QSpinBox *mpDasslMaxIntegrationOrderSpinBox;
  Label *mpCflagsLabel;
  QLineEdit *mpCflagsTextBox;
  Label *mpNumberOfProcessorsLabel;
  QSpinBox *mpNumberOfProcessorsSpinBox;
  Label *mpNumberOfProcessorsNoteLabel;
  QCheckBox *mpBuildOnlyCheckBox;
  QCheckBox *mpLaunchTransformationalDebuggerCheckBox;
  QCheckBox *mpLaunchAlgorithmicDebuggerCheckBox;
  // Output Tab
  QWidget *mpOutputTab;
  Label *mpOutputFormatLabel;
  QComboBox *mpOutputFormatComboBox;
  Label *mpFileNameLabel;
  QLineEdit *mpFileNameTextBox;
  Label *mpResultFileNameLabel;
  QLineEdit *mpResultFileNameTextBox;
  Label *mpResultFileName;
  Label *mpVariableFilterLabel;
  QLineEdit *mpVariableFilterTextBox;
  QCheckBox *mpProtectedVariablesCheckBox;
  QCheckBox *mpEquidistantTimeGridCheckBox;
  QCheckBox *mpStoreVariablesAtEventsCheckBox;
  QCheckBox *mpShowGeneratedFilesCheckBox;
  // Simulation Flags Tab
  QWidget *mpSimulationFlagsTab;
  QScrollArea *mpSimulationFlagsTabScrollArea;
  Label *mpModelSetupFileLabel;
  QLineEdit *mpModelSetupFileTextBox;
  QPushButton *mpModelSetupFileBrowseButton;
  Label *mpInitializationMethodLabel;
  QComboBox *mpInitializationMethodComboBox;
  Label *mpOptimizationMethodLabel;
  QComboBox *mpOptimizationMethodComboBox;
  Label *mpEquationSystemInitializationFileLabel;
  QLineEdit *mpEquationSystemInitializationFileTextBox;
  QPushButton *mpEquationSystemInitializationFileBrowseButton;
  Label *mpEquationSystemInitializationTimeLabel;
  QLineEdit *mpEquationSystemInitializationTimeTextBox;
  Label *mpClockLabel;
  QComboBox *mpClockComboBox;
  Label *mpLinearSolverLabel;
  QComboBox *mpLinearSolverComboBox;
  Label *mpNonLinearSolverLabel;
  QComboBox *mpNonLinearSolverComboBox;
  Label *mpLinearizationTimeLabel;
  QLineEdit *mpLinearizationTimeTextBox;
  Label *mpOutputVariablesLabel;
  QLineEdit *mpOutputVariablesTextBox;
  Label  *mpProfilingLabel;
  QComboBox *mpProfilingComboBox;
  QCheckBox *mpCPUTimeCheckBox;
  QCheckBox *mpEnableAllWarningsCheckBox;
  QGroupBox *mpLoggingGroupBox;
  QGridLayout *mpLoggingGroupLayout;
  Label *mpAdditionalSimulationFlagsLabel;
  QLineEdit *mpAdditionalSimulationFlagsTextBox;
  QToolButton *mpSimulationFlagsHelpButton;
  // Archived Simulation Flags Tab
  QWidget *mpArchivedSimulationsTab;
  QTreeWidget *mpArchivedSimulationsTreeWidget;
  // buttons
  QPushButton *mpSaveButton;
  QPushButton *mpSaveAndSimulateButton;
  QPushButton *mpSimulateButton;
  QPushButton *mpCancelButton;
  QDialogButtonBox *mpButtonBox;
  QList<SimulationOutputWidget*> mSimulationOutputWidgetsList;
  LibraryTreeItem *mpLibraryTreeItem;
  QString mClassName;
  QString mFileName;
  bool mIsReSimulate;

  void setUpForm();
  bool validate();
  void initializeFields(bool isReSimulate, SimulationOptions simulationOptions);
  bool translateModel(QString simulationParameters);
  SimulationOptions createSimulationOptions();
  void createAndShowSimulationOutputWidget(SimulationOptions simulationOptions);
  void showSimulationOutputWidget(SimulationOutputWidget *pSimulationOutputWidget);
  void saveSimulationSettings();
public:
  void reSimulate(SimulationOptions simulationOptions);
  void showAlgorithmicDebugger(SimulationOptions simulationOptions);
  void simulationProcessFinished(SimulationOptions simulationOptions, QDateTime resultFileLastModifiedDateTime);
public slots:
  void numberOfIntervalsRadioToggled(bool toggle);
  void intervalRadioToggled(bool toggle);
  void updateMethodToolTip(int index);
  void enableDasslOptions(QString method);
  void showIntegrationHelp();
  void updateJacobianToolTip(int index);
  void buildOnly(bool checked);
  void browseModelSetupFile();
  void browseEquationSystemInitializationFile();
  void showSimulationFlagsHelp();
  void showArchivedSimulation(QTreeWidgetItem *pTreeWidgetItem);
  void save();
  void saveAndSimulate();
  void simulate();
private slots:
  void resultFileNameChanged(QString text);
};

#endif // SIMULATIONDIALOG_H
