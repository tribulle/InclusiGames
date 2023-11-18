#include <Arduino.h>
#include "../include/image_processing/image_processing.h"

void setup() {
  const void* g_model;
  ImageProcessing::InitializeModel(g_model);
}

void loop() {
  // input->data.int8[0] = x_quantized;
  // Run inference, and report any error
  TfLiteStatus invoke_status = ImageProcessing::interpreter->Invoke();
  if (invoke_status != kTfLiteOk) {
    TF_LITE_REPORT_ERROR(ImageProcessing::error_reporter, "Invoke failed");
    return;
  }
}
