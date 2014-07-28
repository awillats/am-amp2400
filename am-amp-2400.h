#include <QtGui>
#include <daq.h>
#include <default_gui_model.h>

class AMAmpComboBox : public QComboBox {

	Q_OBJECT

	public:
		AMAmpComboBox(QWidget * =0);
		~AMAmpComboBox(void);
		void blacken(void);
		QPalette palette;

	public slots:
		void redden(void);
};


class AMAmpSpinBox : public QSpinBox {

	Q_OBJECT

	public:
		AMAmpSpinBox(QWidget * =0);
		~AMAmpSpinBox(void);
		void blacken(void);
		QPalette palette;

	public slots:
		void redden(void);
};


class AMAmp : public DefaultGUIModel {
	
	Q_OBJECT
	
	public:
		AMAmp(void);
		virtual ~AMAmp(void);
	
		void initParameters(void);
		void customizeGUI(void);
		void updateDAQ(void);
		void updateGUI(void);
	
	protected:
		virtual void update(DefaultGUIModel::update_flags_t);

	private:
		double iclamp_ai_gain; // (1 V / V)
		double iclamp_ao_gain; // (2 nA / V) ...hmm
		double izero_ai_gain; // (1 V / V)
		double izero_ao_gain; // No output
		double vclamp_ai_gain; // 1 mV / pA
		double vclamp_ao_gain; // 20 mV / V

		int input_channel, output_channel;
		int amp_mode, temp_mode;

		DAQ::Device *device;
	
		QRadioButton *iclampButton, *vclampButton, *izeroButton, *vcompButton, *vtestButton, *iresistButton, *ifollowButton;
		QButtonGroup *ampButtonGroup;
		AMAmpSpinBox *inputBox, *outputBox;
		AMAmpComboBox *headstageBox, *outputGainBox;

	private slots:
		void updateMode(int);
		void updateInputChannel(int);
		void updateOutputChannel(int);
};