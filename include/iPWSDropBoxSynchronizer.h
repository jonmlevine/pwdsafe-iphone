// Copyright (c) 2010, Erik J. Johnson
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, 
// are permitted provided that the following conditions are met:
//
// Redistributions of source code must retain the above copyright notice, this list
// of conditions and the following disclaimer.
//
// Redistributions in binary form must reproduce the above copyright notice, this list of 
// conditions and the following disclaimer in the documentation and/or other materials 
// provided with the distribution.
//
// Neither the name of Erik J. Johnson nor the names of its contributors may be used 
// to endorse or promote products derived from this software without specific prior 
// written permission.
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
// OF SUCH DAMAGE.


#import <UIKit/UIKit.h>
#import "iPWSDatabaseModel.h"
#import "iPWSDropBoxAuthenticator.h"
#import "iPWSDropBoxConflictResolver.h"
#import "DropboxSDK/DropboxSDK.h"

//------------------------------------------------------------------------------------
// Class: iPWSDropBoxSynchronizer
// Description:
//  The Dropbox synchronizer tracks a given database models and keeps it in sync with
//  Dropbox.  The synchronizer watches for when the model changes and typically silently merges with the
//  same named file on Dropbox.  This merge process could be transparent, or require manual intervention, depending
//  on whether or not conflicts arise.
@interface iPWSDropBoxSynchronizer : UIViewController 
    <iPWSDropBoxAuthenticatorDelegate, iPWSDropBoxConflictResolverDelegate, DBRestClientDelegate> {
    iPWSDatabaseModel   *model;

    IBOutlet UILabel    *statusLabel;
    BOOL                 viewShowing;
    UIBarButtonItem     *cancelButton;
    
    DBRestClient        *dbClient;
}

// Initialize the view with the model to synchronize with
- (id)initWithModel:(iPWSDatabaseModel *)model;

// Stopping the synchronization
- (IBAction)cancelSynchronization;

@end
