/*=========================================================================

   Program: ParaView
   Module: pqCubeAxesPropertyWidget.cxx

   Copyright (c) 2005-2012 Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.2. 

   See License_v1.2.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/

#include "pqCubeAxesPropertyWidget.h"

#include <QCheckBox>
#include <QGridLayout>
#include <QPushButton>

#include "pqCubeAxesEditorDialog.h"
#include "pqPropertiesPanel.h"
#include "pqProxy.h"
#include "vtkSMProxy.h"

#ifndef UNICODE_TEXT
#include <typeinfo>
#include <QApplication>
#define UNICODE_TEXT(text) QApplication::translate(typeid(*this).name(), QString(text).toStdString().c_str(), 0, QApplication::UnicodeUTF8)
#endif

pqCubeAxesPropertyWidget::pqCubeAxesPropertyWidget(vtkSMProxy *smProxy, QWidget
  *parentObject)
  : pqPropertyWidget(smProxy, parentObject)
{
  QGridLayout *layoutLocal = new QGridLayout(this);
  layoutLocal->setMargin(pqPropertiesPanel::suggestedMargin());
  layoutLocal->setHorizontalSpacing(pqPropertiesPanel::suggestedHorizontalSpacing());
  layoutLocal->setVerticalSpacing(pqPropertiesPanel::suggestedVerticalSpacing());

  QCheckBox *checkBox = new QCheckBox(UNICODE_TEXT("\xD0\x9F\xD0\xBE\xD0\xBA\xD0\xB0\xD0\xB7\xD0\xB0\xD1\x82\xD1\x8C\x20\xD0\xBE\xD1\x81\xD0\xB8"));
  checkBox->setObjectName("VisibilityCheckBox");
  this->addPropertyLink(checkBox, "checked", SIGNAL(toggled(bool)), smProxy->GetProperty("CubeAxesVisibility"));
  layoutLocal->addWidget(checkBox, 0, 0);

  QPushButton *button = new QPushButton(UNICODE_TEXT("\xD0\x98\xD0\xB7\xD0\xBC\xD0\xB5\xD0\xBD\xD0\xB8\xD1\x82\xD1\x8C"));
  button->setObjectName("EditButton");
  connect(button, SIGNAL(clicked()), SLOT(showEditorDialog()));
  layoutLocal->addWidget(button, 0, 1);

  button->setEnabled(checkBox->isChecked());
  QObject::connect(checkBox, SIGNAL(toggled(bool)),
    button, SLOT(setEnabled(bool)));
}

void pqCubeAxesPropertyWidget::showEditorDialog()
{
  pqCubeAxesEditorDialog dialog;
  dialog.setRepresentationProxy(this->proxy());
  dialog.exec();
}
