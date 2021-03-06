#include "VQRecognizer.h"
#include "VQModel.h"

VQRecognizer::VQRecognizer()
 : mWeightingEnabled(true)
{

}

VQRecognizer::~VQRecognizer()
{

}

void VQRecognizer::SetWeightingEnabled(bool enabled)
{
    mWeightingEnabled = enabled;

    Unprepare();
}

bool VQRecognizer::IsWeightingEnabled() const
{
    return mWeightingEnabled;
}

void VQRecognizer::Train()
{
    ModelRecognizer::Train();
}

void VQRecognizer::PrepareModels()
{
    ModelRecognizer::PrepareModels();
    
    if (mWeightingEnabled)
    {
        std::map< SpeakerKey, std::shared_ptr<Model> > weightModels;
        
        if (GetBackgroundModel() != nullptr)
        {    
            weightModels.emplace(SpeakerKey(".ubm"), GetBackgroundModel());
        }

        // Include speaker models.
        weightModels.insert(GetSpeakerModels().begin(), GetSpeakerModels().end());

        // Include impostor models for now.
        weightModels.insert(GetImpostorModels().begin(), GetImpostorModels().end());

        for (auto& model : weightModels)
        {
            VQModel* m = dynamic_cast<VQModel*>(model.second.get());

            m->Weight(weightModels);
        }
    }

    else
    {
        VQModel* m = dynamic_cast<VQModel*>(GetBackgroundModel().get());

        if (m != nullptr)
        {
            m->ResetWeights();
        }

        for (auto& model : GetSpeakerModels())
        {
            m = dynamic_cast<VQModel*>(model.second.get());
            m->ResetWeights();
        }

        for (auto& model : GetImpostorModels())
        {
            m = dynamic_cast<VQModel*>(model.second.get());
            m->ResetWeights();
        }
    }
}

void VQRecognizer::Test(const std::shared_ptr<SpeechData>& data, std::map<SpeakerKey, RecognitionResult>& results)
{
    ModelRecognizer::Test(data, results);
}

std::shared_ptr<Model> VQRecognizer::CreateModel()
{
    return std::make_shared<VQModel>();
}
